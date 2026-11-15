#include "personagem.h"
#include "stdafx.h"

namespace TrabalhoJogo {
namespace Entidades{
namespace Personagens{

Personagem::Personagem(float x, float y, int vida): Entidade(x, y), vida(vida), tempo(0.f), gravidade(900.f), noAr(true){
}

Personagem::~Personagem(){
}

void Personagem::setVida(int vida){
    
    this->vida=vida;
}

int Personagem::getVida(){
    
    return vida;
}

void Personagem::Dano(){
    
    if (vida>0){
        
        vida --;
    }
}

bool Personagem::morto(){
    return vida <=0;
}

void Personagem::setTempo(float tempo) {
    this->tempo = tempo;
}

void Personagem::pular() {
    if (!noAr) {
        velY = -450.f;
        noAr = true;
    }
}

void Personagem::pousar(float posY) {
    y = posY;
    velY = 0.f;
    noAr = false;
    
    figura.setPosition(x, y);
}

void Personagem::aplicarFisica() {
    // Movimento horizontal (MRU)
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
