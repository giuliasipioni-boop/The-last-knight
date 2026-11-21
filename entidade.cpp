#include "entidade.h"
#include "ente.h"

namespace TrabalhoJogo {
namespace Entidades {

Entidade::Entidade(float x, float y) : Ente(), x(x), y(y), velX(0.0), velY(0.0)
{
    figura.setPosition(this->x, this->y);
}

Entidade::~Entidade(){
}

void Entidade::setPosicao(float x, float y){
    
    this->x = x;
    this->y = y;
    
    figura.setPosition(this->x, this->y);
}

void Entidade::setVelocidade(float velX, float velY){
    
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

}
}
