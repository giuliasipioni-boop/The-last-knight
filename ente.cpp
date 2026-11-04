#include "ente.h"
#include "gerenciador_grafico.h"

Gerenciador_grafico* Ente::pGG=nullptr;

Ente::Ente(int id):id(0){

    id++;

 }

Ente::~Ente(){

}

void Ente::setGG(Gerenciador_grafico* pG){

    pGG = pG;

}

void Ente::desenhar(){

    if(pGG != nullptr){
        pGG->desenharEnte(this);
    }

}

void Ente::setTextura(const sf::Texture& textura){

    figura.setTexture(textura);

}

const sf::Drawable& Ente::getFigura() const{

    return figura;

}
