#include "ente.h"
#include "gerenciador_grafico.h"

namespace TheLastKnights {

Gerenciadores::Gerenciador_grafico* Ente::pGG=nullptr;
int Ente::proxID = 0;

Ente::Ente():id(proxID++){
}

Ente::~Ente(){
}

void Ente::setGG(Gerenciadores::Gerenciador_grafico* pG){
    
    pGG = pG;
}

void Ente::desenhar(){
    
    if(pGG != nullptr){
        pGG->desenharEnte(this);
    }
}

void Ente::setTextura(const sf::Texture& textura){
    
    figura.setTexture(textura, true);
}

const sf::Drawable& Ente::getFigura() const{
    
    return figura;
}

int Ente::getID(){
    
    return id;
}


//revisar
void Ente::setEscala(float escala) {
    figura.setScale(escala, escala);
}


//revisar
void Ente::virar(bool direita) {

    float escala = figura.getScale().y;

    if (direita) {
        figura.setScale(escala, escala);
    }
    else {
        figura.setScale(-escala, escala);
    }
}


}
