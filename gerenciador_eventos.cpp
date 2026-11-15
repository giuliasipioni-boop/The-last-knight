#include "gerenciador_eventos.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Gerenciadores {

Gerenciador_eventos::Gerenciador_eventos(sf::RenderWindow* janela, Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2) : pJanela(janela), pJogador1(jog1),pJogador2(jog2) {
}

Gerenciador_eventos::~Gerenciador_eventos() {
}

//codigo obtido a partir do video do monitor Giovane
void Gerenciador_eventos::executar() {
    if (pJanela == 0) {
        return;
    }

    sf::Event evento;

    while (pJanela->pollEvent(evento)) {

        if (evento.type == sf::Event::Closed) {
            pJanela->close();
        }

        if (evento.type == sf::Event::KeyPressed) {
            if (!evento.key.repeat) {
                verificarTeclaPressionada(evento.key.code);
            }
        }

        if (evento.type == sf::Event::KeyReleased) {
            verificarTeclaSolta(evento.key.code);
        }
    }
}


void Gerenciador_eventos::verificarTeclaPressionada(
    sf::Keyboard::Key tecla) {

    // Jogador 1

    if (pJogador1 != 0 && !pJogador1->estaMorto()) {

        if (tecla == sf::Keyboard::A) {
            pJogador1->setDirecao(-1);
        }

        if (tecla == sf::Keyboard::D) {
            pJogador1->setDirecao(1);
        }

        if (tecla == sf::Keyboard::W) {
            pJogador1->pular();
        }

        if (tecla == sf::Keyboard::F) {
            pJogador1->atacar();
        }
    }

    // Jogador 2

    if (pJogador2 != 0 && !pJogador2->estaMorto()) {

        if (tecla == sf::Keyboard::Left) {
            pJogador2->setDirecao(-1);
        }

        if (tecla == sf::Keyboard::Right) {
            pJogador2->setDirecao(1);
        }

        if (tecla == sf::Keyboard::Up) {
            pJogador2->pular();
        }

        if (tecla == sf::Keyboard::K) {
            pJogador2->atacar();
        }
    }
}

void Gerenciador_eventos::verificarTeclaSolta(
    sf::Keyboard::Key tecla) {

    // Jogador 1

    if (pJogador1 != 0) {

        if (tecla == sf::Keyboard::A) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                pJogador1->setDirecao(1);
            }
            else {
                pJogador1->setDirecao(0);
            }
        }

        if (tecla == sf::Keyboard::D) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                pJogador1->setDirecao(-1);
            }
            else {
                pJogador1->setDirecao(0);
            }
        }
    }

    // Jogador 2

    if (pJogador2 != 0) {

        if (tecla == sf::Keyboard::Left) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                pJogador2->setDirecao(1);
            }
            else {
                pJogador2->setDirecao(0);
            }
        }

        if (tecla == sf::Keyboard::Right) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                pJogador2->setDirecao(-1);
            }
            else {
                pJogador2->setDirecao(0);
            }
        }
    }
}



}
}
