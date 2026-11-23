#include "gerenciador_eventos.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Gerenciadores {

Gerenciador_eventos::Gerenciador_eventos(sf::RenderWindow* janela, Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2) : pJanela(janela), pJogador1(jog1),pJogador2(jog2) {
    if (pJanela != 0) {
            pJanela->setKeyRepeatEnabled(false);
        }
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
            verificarTeclasPressionada(evento.key.code);
        }

        if (evento.type == sf::Event::KeyReleased) {
            verificarTeclaSolta(evento.key.code);
        }
    }
}


void Gerenciador_eventos::verificarTeclasPressionada(sf::Keyboard::Key tecla) {
    // Jogador 1

    if (pJogador1 != 0 && !pJogador1->morto()) {

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
            pJogador1->setAtacando(true);
        }
    }

    // Jogador 2

    if (pJogador2 != 0 && !pJogador2->morto()) {

        if (tecla == sf::Keyboard::Left) {
            pJogador2->setDirecao(-1);
        }

        if (tecla == sf::Keyboard::Right) {
            pJogador2->setDirecao(1);
        }

        if (tecla == sf::Keyboard::Up) {
            pJogador2->pular();
        }

        if (tecla == sf::Keyboard::Enter) {
            pJogador2->setAtacando(true);
        }
    }
    
}


void Gerenciador_eventos::verificarTeclaSolta(sf::Keyboard::Key tecla) {

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
