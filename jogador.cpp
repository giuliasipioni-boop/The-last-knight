#include "jogador.h"
#include "gerenciador_grafico.h"

Jogador::Jogador(int id, int x, int y, int num): Personagem(id, x, y, 5), nJog(num), pontosJog(0){
    figura.setSize(sf::Vector2f(40.f, 40.f));
    figura.setFillColor(sf::Color::Green);
}

Jogador::~Jogador(){

}

void Jogador::mover(){

    velX = 0;
    velY = 0;

    if (nJog == 1 && pGG != nullptr)
    {
        if (pGG->teclaPressionada(sf::Keyboard::A))
        {
            velX = -5;
        }

        if (pGG->teclaPressionada(sf::Keyboard::D))
        {
            velX = 5;
        }

        if (pGG->teclaPressionada(sf::Keyboard::W))
        {
            velY = -5;
        }

        if (pGG->teclaPressionada(sf::Keyboard::S))
        {
            velY = 5;
        }
    }


    x += velX;
    y += velY;

    figura.setPosition(x, y);
}

void Jogador::executar(){
    mover();
}

void Jogador::salvar(){

    //fazer quando implementarmos o salvamento
    
}
