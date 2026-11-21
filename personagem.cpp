#include "personagem.h"
#include "stdafx.h"

namespace TrabalhoJogo {
namespace Entidades{
namespace Personagens{

Personagem::Personagem(float x, float y, int vida): Entidade(x, y), vida(vida), tempo(0.0), gravidade(900.0), noAr(true){
}

Personagem::~Personagem(){
}

void Personagem::setVida(int vida){
    
    this->vida=vida;
}

int Personagem::getVida(){
    
    return vida;
}

void Personagem::operator--(){
    
    if (vida>0){
        
        vida --;
    }
}

void Personagem::Dano(){
    
    operator--();
}

bool Personagem::morto(){
    return vida <=0;
}

void Personagem::setTempo(float tempo) {
    this->tempo = tempo;
}

//revisar
void Personagem::pular() {
    if (!noAr) {
        velY = -450.0;
        noAr = true;
    }
}


//revisar
void Personagem::pousar(float posY) {
    y = posY;
    velY = 0.0;
    noAr = false;
    
    figura.setPosition(x, y);
}

void Personagem::aplicarFisica() {
    // Movimento retilineo uniforme (MRU)
    x += velX * tempo;
    
    // Gravidade
    velY += gravidade * tempo;
    y += velY * tempo;
    
    figura.setPosition(x, y);
    
    noAr = true;
}


}
}
}
