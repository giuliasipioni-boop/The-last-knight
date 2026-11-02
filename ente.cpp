#include "ente.h"
#include "gerenciador_grafico.h"

Gerenciador_grafico* Ente::pGG=nullptr;

Ente::Ente(int id):id(0){

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

const sf::Drawable& Ente::getFigura() const{

    return figura;

}
