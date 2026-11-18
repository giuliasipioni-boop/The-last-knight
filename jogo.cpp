
#include "jogo.h"

#include "ente.h"
#include "jogador.h"
#include "esqueleto.h"
#include "mago.h"
#include "rei.h"
#include "gerenciador_eventos.h"
#include "gerenciador_colisoes.h"
#include "lista_entidades.h"
#include "chao.h"

namespace TrabalhoJogo {

using namespace Entidades::Personagens;
using namespace Gerenciadores;

Jogo::Jogo():pJog1(0) {
    Ente::setGG(&grafico);
}

Jogo::~Jogo() {
}

void Jogo::executar() {

    // Personagens
    Jogador jogador(100.f, 300.f, 1);
    Esqueleto esqueleto(900.f, 300.f);
    Mago mago(900.f, 300.f);
    Rei rei(900.f, 300.f);

    pJog1 = &jogador;

    // Escalas que ja estavam funcionando
    esqueleto.setEscala(0.80f);
    mago.setEscala(0.75f);
    rei.setEscala(0.40f);

    // Mago persegue o jogador
    mago.setJogadores(&jogador, 0);
    rei.setJogadores(&jogador, 0);

    // Gerenciador de eventos
    Gerenciador_eventos eventos(&grafico.getJanela(),&jogador,0);

    // Gerenciador de colisoes
    Gerenciador_colisoes colisoes(&jogador,0);

    colisoes.setLimites(1280.f, 620.f);
    colisoes.incluirInimigo(&esqueleto);
    colisoes.incluirInimigo(&mago);
    colisoes.incluirInimigo(&rei);

    // Lista de entidades
    Listas::ListaEntidades entidades;
    entidades.incluir(&jogador);
    entidades.incluir(&esqueleto);
    entidades.incluir(&mago);
    entidades.incluir(&rei);

    //Chao
    Entidades::Chao chao(0.f, 620.f, 1280.f, 100.f);
    // Retangulo usado somente para colisao
    sf::RectangleShape areaChao(sf::Vector2f(1280.f, 100.f));
    areaChao.setPosition(0.f, 620.f);
    colisoes.incluirChao(&areaChao);
    
    sf::Clock relogio;

    while (grafico.jogoAberto()) {

        float dt = relogio.restart().asSeconds();

        if (dt > 0.05f) {
            dt = 0.05f;
        }

        // 1. Eventos do teclado
        eventos.executar();

        if (!grafico.jogoAberto()) {
            break;
        }

        // 2. Atualiza o tempo
        jogador.setTempo(dt);
        esqueleto.setTempo(dt);
        mago.setTempo(dt);
        rei.setTempo(dt);
        colisoes.setTempo(dt);

        // 3. Movimentacao das entidades
        entidades.percorrer();

        // 4. Colisoes
        colisoes.executar();

        // 5. Direcao dos sprites
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

        // 6. Desenho
        grafico.iniciarImagJogo();
        entidades.desenhar();
        grafico.mostrarJogo();
    }

    pJog1 = 0;
}

}
