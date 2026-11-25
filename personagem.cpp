#include "personagem.h"
#include "stdafx.h"

namespace TrabalhoJogo {
namespace Entidades{
namespace Personagens{

Personagem::Personagem(float x, float y, int vida): Entidade(x, y), vida(vida){
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

//revisar
void Personagem::pular() {
    if (!noAr) {
        velY = -550.0;
        noAr = true;
    }
}


}
}
}
