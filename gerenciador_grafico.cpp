#include "gerenciador_grafico.h"
//#include "ente.h"


Gerenciador_grafico::Gerenciador_grafico():janelaJogo(sf::VideoMode(1280, 720), "The Last Knight"){

   janelaJogo.setFramerateLimit(120);

}

Gerenciador_grafico::~Gerenciador_grafico(){

}

void Gerenciador_grafico::desenharFigura(const sf::Drawable& figura){

    janelaJogo.draw(figura);

}

void Gerenciador_grafico::desenharEnte(Ente* pE){

    if(pE != nullptr){
        desenharFigura(pE->getFigura());
    }
}

void Gerenciador_grafico::limparTela(){

    janelaJogo.clear();

}

void Gerenciador_grafico::mostrarJogo(){

    janelaJogo.display();

}

bool Gerenciador_grafico::jogoAberto()const {

    return janelaJogo.isOpen();

}

void Gerenciador_grafico::processarEventos(){

    sf::Event evento;

    while (janelaJogo.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            janelaJogo.close();
        }
    }

}

bool Gerenciador_grafico::teclaPressionada(sf::Keyboard::Key tecla) const
{
    return sf::Keyboard::isKeyPressed(tecla);
}




