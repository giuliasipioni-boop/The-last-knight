#include "gerenciador_colisoes.h"

#include "entidade.h"
#include "personagem.h"
#include "jogador.h"
#include "inimigo.h"
#include "esqueleto.h"
#include "mago.h"
#include "rei.h"
#include "barril.h"
#include "plataforma.h"
#include <cmath>


namespace TrabalhoJogo {
namespace Gerenciadores {

using namespace Entidades;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;


// Codigo do Peteco
Gerenciador_colisoes::Gerenciador_colisoes(Jogador* jog1,Jogador* jog2):LIs(),LOs(),LPs(),pJog1(jog1), pJog2(jog2), pChao(0), larguraTela(1280.0), alturaTela(720.0), topoChao(620.0),tempo(0.0), tempoDano1(0.0),tempoDano2(0.0) {
}


Gerenciador_colisoes::~Gerenciador_colisoes() {
    LIs.clear();
    LOs.clear();
    LPs.clear();
}


// Codigo do Peteco
// Utilizamos getFigura() no lugar de getBounds().
sf::FloatRect Gerenciador_colisoes::getLimites(const Entidade* pE) const {
    
    if (pE == 0) {
        return sf::FloatRect();
    }
    
    const sf::Sprite& sprite = static_cast<const sf::Sprite&>(
                                                              pE->getFigura()
                                                              );
    
    return sprite.getGlobalBounds();
}


// Codigo do Peteco
bool Gerenciador_colisoes::verificarColisao(const Entidade* pe1,const Entidade* pe2) const {
    
    if (pe1 == 0 || pe2 == 0) {
        return false;
    }
    
    return getLimites(pe1).intersects(getLimites(pe2));
    
}



void Gerenciador_colisoes::setJog1(Jogador* pJ) {
    pJog1 = pJ;
}


void Gerenciador_colisoes::setJog2(Jogador* pJ) {
    pJog2 = pJ;
}


// Codigo do Peteco
void Gerenciador_colisoes::incluirInimigo(Inimigo* pI) {
    
    if (pI != 0) {
        LIs.push_back(pI);
    }
}


// Codigo do Peteco
void Gerenciador_colisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO) {
    
    if (pO != 0) {
        LOs.push_back(pO);
    }
}


// Codigo do Peteco
void Gerenciador_colisoes::incluirProjetil(Entidades::Projetil* pP) {
    
    if (pP != 0) {
        LPs.insert(pP);
    }
}


// Codigo do Peteco
void Gerenciador_colisoes::incluirChao(sf::RectangleShape* pC) {
    pChao = pC;
}


void Gerenciador_colisoes::setLimites(float largura, float chao) {
    
    larguraTela = largura;
    topoChao = chao;
}


void Gerenciador_colisoes::setTempo(float dt) {
    
    if (dt >= 0.f) {
        tempo = dt;
    }
}


// Codigo do Peteco
// Impede personagens de sairem da janela.
// O Esqueleto inverte a direcao ao atingir as bordas.
void Gerenciador_colisoes::verificarLimites(Personagem* pP) {
    
    if (pP == 0 || pP->morto()) {
        return;
    }
    
    float x = pP->getPosicaoX();
    float y = pP->getPosicaoY();
    float velocidade = pP->getVelocidadeX();
    
    const float limiteEsquerdo = 100.0;
    const float limiteDireito = 1150.0;
    
    Esqueleto* pEsqueleto = dynamic_cast<Esqueleto*>(pP);
    
    // Parede esquerda
    if (x <= limiteEsquerdo) {
        
        if (pEsqueleto != 0 && velocidade < 0.0) {
            pEsqueleto->inverterDirecao();
            pP->setPosicao(limiteEsquerdo + 5.0, y);
        }
        else if (x < limiteEsquerdo) {
            pP->setPosicao(limiteEsquerdo, y);
        }
    }
    
    // Parede direita
    else if (x >= limiteDireito) {
        
        if (pEsqueleto != 0 && velocidade > 0.0) {
            pEsqueleto->inverterDirecao();
            pP->setPosicao(limiteDireito - 5.0, y);
        }
        else if (x > limiteDireito) {
            pP->setPosicao(limiteDireito, y);
        }
    }
    
    // Limite superior
    if (y < 0.f) {
        pP->setPosicao(pP->getPosicaoX(), 0.0);
        
        if (pP->getVelocidadeY() < 0.0) {
            pP->setVelocidade(pP->getVelocidadeX(), 0.0);
        }
    }
}


// Codigo do Peteco
void Gerenciadores::Gerenciador_colisoes::tratarColisoesChaoJogadores() {
    
    Jogador* jogadores[2] = {pJog1,pJog2};
    
    float yChao = topoChao;
    
    if (pChao != 0) {
        yChao = pChao->getGlobalBounds().top;
    }
    
    for (int i = 0; i < 2; i++) {
        
        Jogador* pJog = jogadores[i];
        
        if (pJog == 0 || pJog->morto()) {
            continue;
        }
        
        sf::FloatRect limites = getLimites(pJog);
        float fundo = limites.top + limites.height;
        
        if (fundo >= yChao && pJog->getVelocidadeY() >= 0.f) {
            pJog->pousar(pJog->getPosicaoY() + yChao - fundo);
        }
    }
}


// Codigo do Peteco
void Gerenciadores::Gerenciador_colisoes::tratarColisoesChaoInimigos() {
    
    float yChao = topoChao;
    
    if (pChao != 0) {
        yChao = pChao->getGlobalBounds().top;
    }
    
    for (unsigned int i = 0; i < LIs.size(); i++) {
        
        Inimigo* pInim = LIs[i];
        
        if (pInim == 0 || pInim->morto()) {
            continue;
        }
        
        sf::FloatRect limites = getLimites(pInim);
        float fundo =limites.top + limites.height;
        
        if (fundo >= yChao &&
            pInim->getVelocidadeY() >= 0.f) {
            pInim->pousar(pInim->getPosicaoY() + yChao - fundo);
        }
    }
}


// Codigo do Peteco
void Gerenciador_colisoes::tratarColisoesJogsObstacs() {

    verificarLimites(pJog1);
    verificarLimites(pJog2);

    for (unsigned int i = 0; i < LIs.size(); i++) {
        verificarLimites(LIs[i]);
    }

    std::list<Obstaculo*>::iterator it;

    for (it = LOs.begin(); it != LOs.end(); ++it) {

        Obstaculo* pObs = (*it);

        if (pObs == nullptr) {
            continue;
        }

        Barril* pB = dynamic_cast<Barril*>(pObs);
        Plataforma* pPlat = dynamic_cast<Plataforma*>(pObs);

        // Colisao do barril com o chao
        if (pB != nullptr) {

            float yChao = topoChao;

            if (pChao != nullptr) {
                yChao = pChao->getGlobalBounds().top;
            }

            sf::FloatRect limites = getLimites(pB);

            float fundo = limites.top + limites.height;

            if (fundo >= yChao &&
                pB->getVelocidadeY() >= 0.0) {

                pB->pousar(
                    pB->getPosicaoY() + yChao - fundo
                );
            }
        }

        // Percorre jogadores e inimigos
        for (unsigned int j = 0; j < LIs.size() + 2; j++) {

            Personagem* pP = nullptr;

            if (j == 0) {
                pP = pJog1;
            }
            else if (j == 1) {
                pP = pJog2;
            }
            else {
                pP = LIs[j - 2];
            }

            if (pP == nullptr || pP->morto()) {
                continue;
            }

            sf::FloatRect personagem = getLimites(pP);
            sf::FloatRect obstaculo = getLimites(pObs);
            sf::FloatRect intersecao;

            // COLISAO COM PLATAFORMAS
            if (pPlat != nullptr) {

                float fundo = personagem.top + personagem.height;

                float fundoAnterior =
                    fundo - pP->getVelocidadeY() * tempo;

                bool dentroX =
                    personagem.left + personagem.width >
                    obstaculo.left &&
                    personagem.left <
                    obstaculo.left + obstaculo.width;

                if (dentroX &&
                    pP->getVelocidadeY() >= 0.0 &&
                    fundoAnterior <= obstaculo.top + 1.0 &&
                    fundo >= obstaculo.top) {

                    pP->pousar(
                        pP->getPosicaoY() +
                        obstaculo.top - fundo
                    );
                }
            }

            // COLISAO COM BARRIS
            else if (pB != nullptr &&
                     personagem.intersects(obstaculo, intersecao)) {

                // Colisao lateral
                if (intersecao.width < intersecao.height) {

                    if (personagem.left + personagem.width / 2 <
                        obstaculo.left + obstaculo.width / 2) {

                        pP->setPosicao(
                            pP->getPosicaoX() + obstaculo.left -
                            (personagem.left + personagem.width),
                            pP->getPosicaoY()
                        );
                    }
                    else {

                        pP->setPosicao(
                            pP->getPosicaoX() + obstaculo.left +
                            obstaculo.width - personagem.left,
                            pP->getPosicaoY()
                        );
                    }

                    Esqueleto* pE = dynamic_cast<Esqueleto*>(pP);
                    Mago* pM = dynamic_cast<Mago*>(pP);

                    if (pE != nullptr) {
                        pE->inverterDirecao();
                    }
                    else if (pM != nullptr) {
                        pM->pular();
                    }
                    else {
                        pB->obstaculizar(pP);
                    }
                }

                // Colisao vertical
                else {

                    if (personagem.top + personagem.height / 2 <
                        obstaculo.top + obstaculo.height / 2) {

                        pP->pousar(
                            pP->getPosicaoY() + obstaculo.top -
                            (personagem.top + personagem.height)
                        );
                    }
                    else {

                        pP->setPosicao(
                            pP->getPosicaoX(),
                            pP->getPosicaoY() + obstaculo.top +
                            obstaculo.height - personagem.top
                        );

                        pP->setVelocidade(
                            pP->getVelocidadeX(), 0.0
                        );
                    }
                }
            }
        }
    }
}

// Codigo do Peteco
void Gerenciadores::Gerenciador_colisoes::tratarColisoesJogsInimgs(){
    
    for (unsigned int i = 0; i < LIs.size(); i++) {
        
        Inimigo* pInim = LIs[i];
        
        if (pInim == 0 || pInim->morto()) {
            continue;
        }
        
        // Area de colisao reduzida do inimigo
        sf::FloatRect areaInim = getLimites(pInim);
        
        areaInim.left += areaInim.width * 0.30;
        areaInim.width *= 0.40;
        
        areaInim.top += areaInim.height * 0.20;
        areaInim.height *= 0.60;
        
        // Jogador 1
        if (pJog1 != 0 && !pJog1->morto() && tempoDano1 <= 0.0) {
            
            sf::FloatRect areaJog = getLimites(pJog1);
            
            areaJog.left += areaJog.width * 0.30;
            areaJog.width *= 0.40;
            
            areaJog.top += areaJog.height * 0.20;
            areaJog.height *= 0.60;
            
            if (areaJog.intersects(areaInim)) {
                pInim->danificar(pJog1);
                tempoDano1 = 2.0;
            }
        }
        
        // Jogador 2
        if (pJog2 != 0 && !pJog2->morto() && tempoDano2 <= 0.0) {
            
            sf::FloatRect areaJog = getLimites(pJog2);
            
            areaJog.left += areaJog.width * 0.30;
            areaJog.width *= 0.40;
            
            areaJog.top += areaJog.height * 0.20;
            areaJog.height *= 0.60;
            
            if (areaJog.intersects(areaInim)) {
                pInim->danificar(pJog2);
                tempoDano2 = 2.0;
            }
        }
    }
}

// Codigo do Peteco - estrutura mantida.
// A colisao com projeteis sera feita quando
// o Rei estiver lancando os machados.
void Gerenciadores::Gerenciador_colisoes::tratarColisoesJogsProjeteis() {
    
    // Ainda nao implementado.
}


void Gerenciador_colisoes::tratarAtaques() {
    
    Jogador* jogadores[2] = {pJog1, pJog2};
    
    for (int j = 0; j < 2; j++) {
        
        Jogador* pJog = jogadores[j];
        
        if (pJog != nullptr && !pJog->morto() && pJog->estaAtacando()) {
            
            sf::FloatRect areaJog = getLimites(pJog);
            
            float xJog = areaJog.left + areaJog.width / 2;
            float yJog = areaJog.top + areaJog.height / 2;
            
            for (size_t i = 0; i < LIs.size(); i++) {
                
                Inimigo* pI = LIs[i];
                
                if (pI != nullptr && !pI->morto()) {
                    
                    sf::FloatRect areaInim = getLimites(pI);
                    
                    float distanciaX = areaInim.left + areaInim.width / 2 - xJog;
                    float distanciaY = areaInim.top + areaInim.height / 2 - yJog;
                    
                    if (distanciaY > -100.0 && distanciaY < 100.0) {
                        
                        if (pJog->getLadoAtaque() == 1 && distanciaX >= 0.0 && distanciaX < 120.0) {
                            pI->Dano();
                            
                        }
                        
                        if (pJog->getLadoAtaque() == -1 && distanciaX <= 0.0 && distanciaX > -120.0) {
                            pI->Dano();
                            
                        }
                    }
                }
            }
            
            pJog->setAtacando(false);
        }
    }
    
    
}
    // Codigo do Peteco
void Gerenciador_colisoes::executar() {

    if (tempoDano1 > 0.0) {
        tempoDano1 -= tempo;
    }

    if (tempoDano2 > 0.0) {
        tempoDano2 -= tempo;
    }

    tratarColisoesChaoJogadores();
    tratarColisoesChaoInimigos();
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsProjeteis();
    tratarAtaques();
}


}
}

