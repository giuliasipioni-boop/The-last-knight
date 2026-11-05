#include "personagem.h"
#include "stdafx.h"

Personagem::Personagem(int x, int y, int vida): Entidade(x, y), vida(5){
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
