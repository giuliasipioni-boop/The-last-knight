#include "entidade.h"
#include "ente.h"

Entidade::Entidade(int x, int y) : Ente(), x(x), y(y), velX(0), velY(0)
{
    figura.setPosition(this->x, this->y);
}

 Entidade::~Entidade(){
 }

 void Entidade::setPosicao(int x, int y){
    
    this->x = x;
    this->y = y;

    figura.setPosition(this->x, this->y);
 }

 void Entidade::setVelocidade(int velX, int velY){

    this->velX = velX;
    this->velY = velY;
}

 int Entidade::getPosicaoX(){
    return x;
}

int Entidade::getPosicaoY(){
    return y;
}

int Entidade::getVelocidadeX(){
    return velX;
}

int Entidade::getVelocidadeY(){
    return velY;
}


