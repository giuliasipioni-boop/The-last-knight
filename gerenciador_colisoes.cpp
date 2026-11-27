#include "gerenciador_colisoes.h"
#include "entidade.h"
#include "jogador.h"
#include "inimigo.h"
#include "esqueleto.h"
#include "mago.h"
#include "obstaculo.h"
#include "plataforma.h"
#include "projetil.h"
#include "chao.h"

#include <cmath>

namespace TheLastKnights {
namespace Gerenciadores {

using namespace std;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;


// ==========================================
// Base: codigo do monitor - Stalingrado
// ==========================================


// Adaptado do Stalingrado

Gerenciador_colisoes::Gerenciador_colisoes(
    Jogador* pJ1, Jogador* pJ2):

    LIs(),
    LOs(),
    LPs(),
    pJog1(pJ1),
    pJog2(pJ2),
    pChao(nullptr),
    larguraTela(1280.f),
    topoChao(620.f),
    tempo(0.f),
    tempoDano1(0.f),
    tempoDano2(0.f) {

}


// Codigo do Stalingrado

Gerenciador_colisoes::~Gerenciador_colisoes(){

    // Limpa os vetores, listas e aterra os ponteiros.
    // A memoria deve ser desalocada na fase.

    pJog1 = pJog2 = nullptr;

    LIs.clear();
    LOs.clear();
    LPs.clear();
}


// Codigo do Stalingrado
// Renomeado conforme o UML

void Gerenciador_colisoes::incluirChao(Chao* pC){

    pChao = pC;
}


// Adaptado do Stalingrado

const bool Gerenciador_colisoes::verificarColisao(
    const Entidade* pe1,
    const Entidade* pe2) const {

    if (pe1 == nullptr || pe2 == nullptr) {
        return false;
    }

    return getLimites(pe1).intersects(getLimites(pe2));
}


// Adaptado do Stalingrado

const bool Gerenciador_colisoes::verificarColisao(
    const Entidade* pe1,
    const Entidade* pe2,
    float margemExtra) const {

    if (pe1 == nullptr || pe2 == nullptr) {
        return false;
    }

    sf::FloatRect caixa1 = getLimites(pe1);
    sf::FloatRect caixa2 = getLimites(pe2);

    // Expande a caixa do inimigo para todos os lados
    // usando a margemExtra

    caixa2.left -= margemExtra;
    caixa2.top -= margemExtra;
    caixa2.width += margemExtra * 2.0f;
    caixa2.height += margemExtra * 2.0f;

    return caixa1.intersects(caixa2);
}


void Gerenciador_colisoes::tratarColisoesChaoObstaculos(){

    for (list<Obstaculo*>::iterator it = LOs.begin();
         it != LOs.end(); ++it) {

        if (dynamic_cast<Plataforma*>(*it) == nullptr) {

            tratarColisoesChao(*it);
        }
    }
}

// Adaptado do Stalingrado

void Gerenciador_colisoes::resolverColisaoCinematica(
    Entidade* pJ, Entidade* pE){

    sobreposicao sob = calcularSobreposicao(pJ, pE);

    if (sob.overlapX > 0.0f && sob.overlapY > 0.0f) {

        if (sob.overlapX < sob.overlapY) {

            // Colisao horizontal

            if (sob.distX > 0) {

                // Empurra para a direita

                moverPos(pJ, sob.overlapX, 0.0f);

            } else {

                // Empurra para a esquerda

                moverPos(pJ, -sob.overlapX, 0.0f);
            }

        } else {

            // Colisao vertical

            if (sob.distY > 0) {

                // Empurra para baixo

                moverPos(pJ, 0.0f, sob.overlapY);

                pJ->setVelocidade(
                    pJ->getVelocidadeX(), 0.0f);

            } else {

                // Empurra para cima

                moverPos(pJ, 0.0f, -sob.overlapY);

                if (pJ->getVelocidadeY() >= 0.0f) {

                    pJ->pousar(pJ->getPosicaoY());
                }
            }
        }
    }
}


// Adaptado do Stalingrado

Gerenciador_colisoes::sobreposicao
Gerenciador_colisoes::calcularSobreposicao(
    Entidade* pJ, Entidade* pE){

    Gerenciador_colisoes::sobreposicao sob;

    sf::FloatRect caixaJog = getLimites(pJ);
    sf::FloatRect caixaObs = getLimites(pE);

    // Calcula os centros de cada caixa

    float centroJogX =
        caixaJog.left + caixaJog.width / 2.0f;

    float centroJogY =
        caixaJog.top + caixaJog.height / 2.0f;

    float centroObsX =
        caixaObs.left + caixaObs.width / 2.0f;

    float centroObsY =
        caixaObs.top + caixaObs.height / 2.0f;

    // Calcula as distancias entre os centros

    sob.distX = centroJogX - centroObsX;
    sob.distY = centroJogY - centroObsY;

    // Calcula a distancia minima para nao haver colisao

    float minX =
        (caixaJog.width / 2.0f) +
        (caixaObs.width / 2.0f);

    float minY =
        (caixaJog.height / 2.0f) +
        (caixaObs.height / 2.0f);

    // Calcula a sobreposicao em cada eixo

    sob.overlapX = minX - std::abs(sob.distX);
    sob.overlapY = minY - std::abs(sob.distY);

    return sob;
}


// Adaptado do Stalingrado

void Gerenciador_colisoes::tratarColisoesJogsObstacs(){

    for (list<Obstaculo*>::iterator it = LOs.begin();
         it != LOs.end(); ++it) {

        if (pJog1 != nullptr && !pJog1->morto() &&
            verificarColisao(pJog1, *it)) {

            resolverColisaoCinematica(pJog1, *it);

            if ((*it)->ehDanoso() && tempoDano1 <= 0.0f) {

                (*it)->obstaculizar(pJog1);

                tempoDano1 = 2.0f;
            }
        }

        if (pJog2 != nullptr && !pJog2->morto() &&
            verificarColisao(pJog2, *it)) {

            resolverColisaoCinematica(pJog2, *it);

            if ((*it)->ehDanoso() && tempoDano2 <= 0.0f) {

                (*it)->obstaculizar(pJog2);

                tempoDano2 = 2.0f;
            }
        }
    }
}


// Adaptado do Stalingrado

void Gerenciador_colisoes::tratarColisoesJogsInimgs(){

    if (pJog1 != nullptr && !pJog1->morto()) {
        verificarLimites(pJog1);
    }

    if (pJog2 != nullptr && !pJog2->morto()) {
        verificarLimites(pJog2);
    }

    for (vector<Inimigo*>::iterator it = LIs.begin();
         it != LIs.end(); ++it) {

        if ((*it)->morto()) {
            continue;
        }

        verificarLimites(*it);

        if (pJog1 != nullptr && !pJog1->morto()) {

            // Dano do jogador ao inimigo

            if (pJog1->estaAtacando() &&
                verificarColisao(pJog1, *it, 60.0f) &&
                ((*it)->getPosicaoX() -
                 pJog1->getPosicaoX()) *
                 pJog1->getLadoAtaque() >= 0.0f) {

                (*it)->Dano();
            }

            // Dano do inimigo ao jogador

            if (!(*it)->morto() &&
                verificarColisao(pJog1, *it)) {

                if (tempoDano1 <= 0.0f) {

                    (*it)->danificar(pJog1);

                    tempoDano1 = 2.0f;
                }
            }
        }

        if (pJog2 != nullptr && !pJog2->morto() &&
            !(*it)->morto()) {

            // Dano do jogador ao inimigo

            if (pJog2->estaAtacando() &&
                verificarColisao(pJog2, *it, 60.0f) &&
                ((*it)->getPosicaoX() -
                 pJog2->getPosicaoX()) *
                 pJog2->getLadoAtaque() >= 0.0f) {

                (*it)->Dano();
            }

            // Dano do inimigo ao jogador

            if (!(*it)->morto() &&
                verificarColisao(pJog2, *it)) {

                if (tempoDano2 <= 0.0f) {

                    (*it)->danificar(pJog2);

                    tempoDano2 = 2.0f;
                }
            }
        }
    }

    if (pJog1 != nullptr) {
        pJog1->setAtacando(false);
    }

    if (pJog2 != nullptr) {
        pJog2->setAtacando(false);
    }
}


// Adaptado do Stalingrado
// Originalmente colisaoBorda()

void Gerenciador_colisoes::verificarLimites(
    Personagem* pP){

    sf::FloatRect caixa = getLimites(pP);

    float dist_centro = caixa.width / 2.0f;

    sf::Vector2f posi(
        caixa.left + dist_centro, caixa.top);

    if (posi.x - dist_centro < 0.0f) {

        float correcaoX = dist_centro - posi.x;

        moverPos(pP, correcaoX, 0.0f);

        pP->setVelocidade(
            0.0f, pP->getVelocidadeY());

        Esqueleto* p = dynamic_cast<Esqueleto*>(pP);

        if (p != nullptr) {
            p->inverterDirecao();
        }

    } else if (posi.x + dist_centro > larguraTela) {

        float correcaoX =
            larguraTela - dist_centro - posi.x;

        moverPos(pP, correcaoX, 0.0f);

        pP->setVelocidade(
            0.0f, pP->getVelocidadeY());

        Esqueleto* p = dynamic_cast<Esqueleto*>(pP);

        if (p != nullptr) {
            p->inverterDirecao();
        }
    }

    if (caixa.top < 0.0f) {

        moverPos(pP, 0.0f, -caixa.top);

        pP->setVelocidade(
            pP->getVelocidadeX(), 0.0f);
    }
}


// Adaptado do Stalingrado

void Gerenciador_colisoes::tratarColisoesJogsProjeteis(){

    for (set<Projetil*>::iterator it = LPs.begin();
         it != LPs.end(); it++) {

        if (!(*it)->estaAtivo()) {
            continue;
        }

        // Verifica colisao com o chao e limites

        if (getLimites(*it).top +
            getLimites(*it).height >= topoChao ||

            getLimites(*it).left +
            getLimites(*it).width < 0.0f ||

            getLimites(*it).left > larguraTela) {

            (*it)->desativar();

            continue;
        }

        if (pJog1 != nullptr && !pJog1->morto() &&
            verificarColisao(pJog1, *it)) {

            (*it)->danificar(pJog1);
        }

        if ((*it)->estaAtivo() &&
            pJog2 != nullptr &&
            !pJog2->morto() &&
            verificarColisao(pJog2, *it)) {

            (*it)->danificar(pJog2);
        }
    }
}


// Adaptado do Stalingrado
// Originalmente colisoesChao()

// Adaptado do Stalingrado

void Gerenciador_colisoes::tratarColisoesChao(Entidade* pE){

    if (pChao == nullptr || pE == nullptr) {
        return;
    }

    sf::FloatRect caixa = getLimites(pE);

    float fundo = caixa.top + caixa.height;
    float yChao = pChao->getPosicaoY();

    if (fundo >= yChao && pE->getVelocidadeY() >= 0.0) {

        pE->pousar(pE->getPosicaoY() + yChao - fundo);
    }
}

// Codigo do Stalingrado

void Gerenciador_colisoes::incluirInimigo(Inimigo* pI){

    LIs.push_back(pI);
}


// Codigo do Stalingrado

void Gerenciador_colisoes::incluirObstaculo(Obstaculo* pO){

    LOs.push_back(pO);
}


// Codigo do Stalingrado

void Gerenciador_colisoes::incluirProjetil(Projetil* pP){

    LPs.insert(pP);
}


// Adaptado do Stalingrado

void Gerenciador_colisoes::executar(){

    if (tempoDano1 > 0.0f) {
        tempoDano1 -= tempo;
    }

    if (tempoDano2 > 0.0f) {
        tempoDano2 -= tempo;
    }

    tratarColisoesChaoObstaculos();
    tratarColisoesChaoJogadores();
    tratarColisoesChaoInimigos();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsProjeteis();
    tratarColisoesJogsObstacs();
    tratarColisoesInimObstacs();
}


// ==========================================
// Codigo desenvolvido pelos autores
// ==========================================


sf::FloatRect Gerenciador_colisoes::getLimites(
    const Entidade* pE) const {

    // O chao nao possui textura

    if (pE == pChao) {

        return sf::FloatRect(
            0.0f, topoChao,
            larguraTela, 720.0f - topoChao);
    }

    if (pE == nullptr) {
        return sf::FloatRect();
    }

    return static_cast<const sf::Sprite&>(
        pE->getFigura()
    ).getGlobalBounds();
}


void Gerenciador_colisoes::moverPos(
    Entidade* pe, float dx, float dy){

    pe->setPosicao(
        pe->getPosicaoX() + dx,
        pe->getPosicaoY() + dy);
}


// Codigo desenvolvido pelos autores
// Utilizando as funcoes do Stalingrado

void Gerenciador_colisoes::tratarColisoesInimObstacs(){

    for (vector<Inimigo*>::iterator it = LIs.begin();
         it != LIs.end(); ++it) {

        Inimigo* pI = *it;

        if (pI->morto()) {
            continue;
        }

        for (list<Obstaculo*>::iterator obs = LOs.begin();
             obs != LOs.end(); ++obs) {

            Obstaculo* pO = *obs;

            if (verificarColisao(pI, pO)) {

                sobreposicao sob =
                    calcularSobreposicao(pI, pO);

                resolverColisaoCinematica(pI, pO);

                if (sob.overlapX < sob.overlapY &&
                    sob.distX * pI->getVelocidadeX() < 0.0) {

                    Esqueleto* pE = dynamic_cast<Esqueleto*>(pI);
                    Mago* pM = dynamic_cast<Mago*>(pI);

                    if (pE != nullptr) {
                        pE->inverterDirecao();
                    }

                    else if (pM != nullptr) {
                        pM->pular();
                    }
                }
            }
        }
    }
}

void Gerenciador_colisoes::setJog1(Jogador* pJ){

    pJog1 = pJ;
}


void Gerenciador_colisoes::setJog2(Jogador* pJ){

    pJog2 = pJ;
}


void Gerenciador_colisoes::setLimites(
    float largura, float chao){

    larguraTela = largura;
    topoChao = chao;
}


void Gerenciador_colisoes::setTempo(float dt){

    tempo = dt;
}


void Gerenciador_colisoes::tratarColisoesChaoJogadores(){

    if (pJog1 != nullptr && !pJog1->morto()) {

        tratarColisoesChao(pJog1);
    }

    if (pJog2 != nullptr && !pJog2->morto()) {

        tratarColisoesChao(pJog2);
    }
}


void Gerenciador_colisoes::tratarColisoesChaoInimigos(){

    for (vector<Inimigo*>::iterator it = LIs.begin();
         it != LIs.end(); ++it) {

        if (!(*it)->morto()) {

            tratarColisoesChao(*it);
        }
    }
}

}

}
