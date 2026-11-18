#include "gerenciador_colisoes.h"

#include "entidade.h"
#include "personagem.h"
#include "jogador.h"
#include "inimigo.h"
#include "esqueleto.h"
#include <cmath>


namespace TrabalhoJogo {
namespace Gerenciadores {

using namespace Entidades;
using namespace Entidades::Personagens;


// Codigo do Peteco
Gerenciador_colisoes::Gerenciador_colisoes(Jogador* jog1,Jogador* jog2) :LIs(),LOs(),LPs(),pJog1(jog1), pJog2(jog2), pChao(0), larguraTela(1280.f), alturaTela(720.f), topoChao(620.f),tempo(0.f), tempoDano1(0.f),tempoDano2(0.f) {
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


// Codigo do Peteco - adaptado para The Last Knight.
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
    
    // Limites provisórios do Esqueleto
   
    Esqueleto* pEsqueleto = dynamic_cast<Esqueleto*>(pP);

    if (pEsqueleto != 0) {

        float x = pEsqueleto->getPosicaoX();
        float velocidade = pEsqueleto->getVelocidadeX();

        // Chegou na parede esquerda
        if (x <= 50.f && velocidade < 0.f) {
            pEsqueleto->inverterDirecao();
            pEsqueleto->setPosicao(
                55.f,
                pEsqueleto->getPosicaoY()
            );
        }

        // Chegou na parede direita
        else if (x >= 1150.f && velocidade > 0.f) {
            pEsqueleto->inverterDirecao();
            pEsqueleto->setPosicao(
                1145.f,
                pEsqueleto->getPosicaoY()
            );
        }

        return;
    }

    sf::FloatRect limites = getLimites(pP);
    
    float x = pP->getPosicaoX();
    float y = pP->getPosicaoY();
    
    float vx = pP->getVelocidadeX();
    float vy = pP->getVelocidadeY();
    
    bool bateuLado = false;
    
    // Limite esquerdo
    if (limites.left < 0.f) {
        
        x -= limites.left;
        
        if (vx < 0.f) {
            bateuLado = true;
        }
    }
    
    // Limite direito
    else if (
             limites.left + limites.width > larguraTela
             ) {
                 
                 float excesso =
                 limites.left + limites.width - larguraTela;
                 
                 x -= excesso;
                 
                 if (vx > 0.f) {
                     bateuLado = true;
                 }
             }
    
    // Limite superior
    if (limites.top < 0.f) {
        
        y -= limites.top;
        
        if (vy < 0.f) {
            vy = 0.f;
        }
    }
    
    pP->setPosicao(x, y);
    pP->setVelocidade(vx, vy);
    
    // Comportamento do Esqueleto do nosso jogo
    if (bateuLado) {
        
        Esqueleto* pEsqueleto = dynamic_cast<Esqueleto*>(pP);
        
        if (pEsqueleto != 0) {
            pEsqueleto->inverterDirecao();
        }
        
    }
}


// Codigo do Peteco - adaptado para The Last Knight.
// Colisao entre jogadores e o chao.
void Gerenciadores::Gerenciador_colisoes::tratarColisoesChaoJogadores() {
    
    Jogador* jogadores[2] = {
        pJog1,
        pJog2
    };
    
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


// Codigo do Peteco - adaptado para The Last Knight.
// Colisao entre inimigos e o chao.
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


// Codigo do Peteco - adaptado para The Last Knight.
// Por enquanto, trata os limites da janela.
// Os obstaculos serao integrados depois.
void Gerenciadores::Gerenciador_colisoes::tratarColisoesJogsObstacs() {
    verificarLimites(pJog1);
    verificarLimites(pJog2);
    
    for (unsigned int i = 0; i < LIs.size(); i++) {
        if (LIs[i] != 0) {
            verificarLimites(LIs[i]);
        }
    }
}


// Codigo do Peteco - adaptado para The Last Knight.
// Percorre o vector de inimigos e verifica
// as colisoes com os jogadores.


void Gerenciadores::Gerenciador_colisoes::tratarColisoesJogsInimgs() {

    for (unsigned int i = 0; i < LIs.size(); i++) {

        Inimigo* pInim = LIs[i];

        if (pInim == 0 || pInim->morto()) {
            continue;
        }

        // Area de colisao reduzida do inimigo
        sf::FloatRect areaInim = getLimites(pInim);

        areaInim.left += areaInim.width * 0.30f;
        areaInim.width *= 0.40f;

        areaInim.top += areaInim.height * 0.20f;
        areaInim.height *= 0.60f;

        // Jogador 1
        if (pJog1 != 0 &&
            !pJog1->morto() &&
            tempoDano1 <= 0.f) {

            sf::FloatRect areaJog = getLimites(pJog1);

            areaJog.left += areaJog.width * 0.30f;
            areaJog.width *= 0.40f;

            areaJog.top += areaJog.height * 0.20f;
            areaJog.height *= 0.60f;

            if (areaJog.intersects(areaInim)) {
                pInim->danificar(pJog1);
                tempoDano1 = 1.f;
            }
        }

        // Jogador 2
        if (pJog2 != 0 &&
            !pJog2->morto() &&
            tempoDano2 <= 0.f) {

            sf::FloatRect areaJog = getLimites(pJog2);

            areaJog.left += areaJog.width * 0.30f;
            areaJog.width *= 0.40f;

            areaJog.top += areaJog.height * 0.20f;
            areaJog.height *= 0.60f;

            if (areaJog.intersects(areaInim)) {
                pInim->danificar(pJog2);
                tempoDano2 = 1.f;
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


// Codigo do Peteco - adaptado para The Last Knight.
// Organiza as verificacoes a cada quadro.
void Gerenciadores::Gerenciador_colisoes::executar() {
    
    if (tempoDano1 > 0.f) {
        tempoDano1 -= tempo;
    }
    
    if (tempoDano2 > 0.f) {
        tempoDano2 -= tempo;
    }
    
    tratarColisoesJogsObstacs();
    tratarColisoesChaoJogadores();
    tratarColisoesChaoInimigos();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsProjeteis();
}

}
}
