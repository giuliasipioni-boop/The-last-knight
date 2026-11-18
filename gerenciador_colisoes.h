#ifndef _GERENCIADOR_COLISOES_H_
#define _GERENCIADOR_COLISOES_H_

#include "stdafx.h"

namespace TrabalhoJogo {

namespace Entidades {

class Entidade;
class Projetil;

namespace Personagens {
class Personagem;
class Jogador;
class Inimigo;
}

namespace Obstaculos {
class Obstaculo;
}

}

namespace Gerenciadores {

class Gerenciador_colisoes {
private:
    std::vector<Entidades::Personagens::Inimigo*> LIs;
    std::list<Entidades::Obstaculos::Obstaculo*> LOs;
    std::set<Entidades::Projetil*> LPs;

    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;

    // Chao e limites provisórios
    sf::RectangleShape* pChao;
    float larguraTela;
    float alturaTela;
    float topoChao;

    float tempo;
    float tempoDano1;
    float tempoDano2;

    sf::FloatRect getLimites(const Entidades::Entidade* pE) const;
    bool verificarColisao(const Entidades::Entidade* pe1, const Entidades::Entidade* pe2) const;
    void verificarLimites(Entidades::Personagens::Personagem* pP);
    
public:
    //construtora e destrutora
    Gerenciador_colisoes(Entidades::Personagens::Jogador* jog1 = 0, Entidades::Personagens::Jogador* jog2=0);
    ~Gerenciador_colisoes();

    void setJog1(Entidades::Personagens::Jogador* pJ);
    void setJog2(Entidades::Personagens::Jogador* pJ);
    void incluirInimigo(Entidades::Personagens::Inimigo* pI);
    void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
    void incluirProjetil(Entidades::Projetil* pP);
    void incluirChao(sf::RectangleShape* pC);

    // Configuracoes da demonstracao
    void setLimites(float largura, float chao);
    void setTempo(float dt);
    
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();
    void tratarColisoesJogsProjeteis();

    // Tratamento do chao baseado no Peteco
    void tratarColisoesChaoJogadores();
    void tratarColisoesChaoInimigos();

    void executar();
};

}
}

#endif



