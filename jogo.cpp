#include "jogo.h"

#include "ente.h"
#include "jogador.h"
#include "esqueleto.h"
#include "mago.h"

#include "gerenciador_eventos.h"
#include "gerenciador_colisoes.h"
#include "lista_entidades.h"

#include <iostream>

namespace TrabalhoJogo {

using namespace Entidades::Personagens;
using namespace Gerenciadores;

Jogo::Jogo() {
    Ente::setGG(&grafico);
}

Jogo::~Jogo() {
}

void Jogo::executar() {

    // Personagens
    Jogador jogador(100.f, 300.f, 1);
    Esqueleto esqueleto(450.f, 300.f);
    Mago mago(900.f, 300.f);

    esqueleto.setEscala(0.90f);
    mago.setEscala(0.75f);

    // O Mago persegue o jogador.
    mago.setJogadores(&jogador, 0);

    // Gerenciador de eventos
    Gerenciador_eventos eventos(
        &grafico.getJanela(),
        &jogador,
        0
    );

    // Gerenciador de colisoes
    Gerenciador_colisoes colisoes(
        &jogador,
        0
    );

    colisoes.setLimites(1280.f, 620.f);

    colisoes.incluirInimigo(&esqueleto);
    colisoes.incluirInimigo(&mago);

    // Lista de entidades
    Listas::ListaEntidades entidades;

    entidades.incluir(&jogador);
    entidades.incluir(&esqueleto);
    entidades.incluir(&mago);

    // Chao temporario
    sf::RectangleShape chao(
        sf::Vector2f(1280.f, 100.f)
    );

    chao.setPosition(0.f, 620.f);
    chao.setFillColor(sf::Color(90, 65, 45));

    colisoes.incluirChao(&chao);

    sf::Clock relogio;

    while (grafico.jogoAberto()) {

        float dt = relogio.restart().asSeconds();

        if (dt > 0.05f) {
            dt = 0.05f;
        }

        // 1. Eventos
        eventos.executar();

        if (!grafico.jogoAberto()) {
            break;
        }

        // 2. Atualiza o tempo
        jogador.setTempo(dt);
        esqueleto.setTempo(dt);
        mago.setTempo(dt);

        colisoes.setTempo(dt);

        // 3. Atualiza as entidades
        entidades.percorrer();
        // Teste da movimentacao do Esqueleto
        static float tempoTeste = 0.f;
        tempoTeste += dt;

        if (tempoTeste >= 1.f) {
            std::cout << "Esqueleto X: "
                      << esqueleto.getPosicaoX()
                      << " | Velocidade: "
                      << esqueleto.getVelocidadeX()
                      << std::endl;

            tempoTeste = 0.f;
        }

        // 4. Verifica as colisoes
        colisoes.executar();

        // 5. Corrige a direcao dos sprites
        // false = imagem original olha para esquerda
        if (jogador.getVelocidadeX() > 0)
            jogador.virar(true);
        else if (jogador.getVelocidadeX() < 0)
            jogador.virar(false);

        if (esqueleto.getVelocidadeX() > 0)
            esqueleto.virar(true);
        else if (esqueleto.getVelocidadeX() < 0)
            esqueleto.virar(false);

        if (mago.getVelocidadeX() > 0)
            mago.virar(true);
        else if (mago.getVelocidadeX() < 0)
            mago.virar(false);

        // 6. Desenha o jogo
        grafico.iniciarImagJogo();

        grafico.desenharFigura(chao);

        entidades.desenhar();

        grafico.mostrarJogo();
    }
}
}


