#pragma once

#include <vector>
#include <list>
#include <set>
#include <SFML/Graphics.hpp>

namespace TheLastKnights {

namespace Entidades {
    class Projetil;
    class Entidade;
    class Chao;

    namespace Obstaculos {
        class Obstaculo;
    }

    namespace Personagens {
        class Personagem;
        class Inimigo;
        class Jogador;
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
    Entidades::Chao* pChao;

    // Estrutura do Stalingrado

    struct sobreposicao {
        float distX;
        float distY;
        float overlapX;
        float overlapY;
    };

    void resolverColisaoCinematica(
        Entidades::Entidade* pJ,
        Entidades::Entidade* pE);

    struct sobreposicao calcularSobreposicao(
        Entidades::Entidade* pJ,
        Entidades::Entidade* pE);

    const bool verificarColisao(
        const Entidades::Entidade* pe1,
        const Entidades::Entidade* pe2) const;

    const bool verificarColisao(
        const Entidades::Entidade* pe1,
        const Entidades::Entidade* pe2,
        float margemExtra) const;

    void tratarColisoesChao(Entidades::Entidade* pe);

    void verificarLimites(
        Entidades::Personagens::Personagem* pP);

public:

    Gerenciador_colisoes(
        Entidades::Personagens::Jogador* pJ1 = nullptr,
        Entidades::Personagens::Jogador* pJ2 = nullptr);

    ~Gerenciador_colisoes();

    void incluirChao(Entidades::Chao* pC);

    void incluirInimigo(
        Entidades::Personagens::Inimigo* pI);

    void incluirObstaculo(
        Entidades::Obstaculos::Obstaculo* pO);

    void incluirProjetil(
        Entidades::Projetil* pP);

    void tratarColisoesChaoObstaculos();
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();
    void tratarColisoesJogsProjeteis();

    void executar();


    // Codigo desenvolvido pelos autores

private:

    float larguraTela;
    float topoChao;
    float tempo;
    float tempoDano1;
    float tempoDano2;

    sf::FloatRect getLimites(
        const Entidades::Entidade* pE) const;

    void moverPos(
        Entidades::Entidade* pe,
        float dx, float dy);

    void tratarColisoesInimObstacs();

public:

    void setJog1(Entidades::Personagens::Jogador* pJ);
    void setJog2(Entidades::Personagens::Jogador* pJ);

    void setLimites(float largura, float chao);
    void setTempo(float dt);

    void tratarColisoesChaoJogadores();
    void tratarColisoesChaoInimigos();
};

}

}
