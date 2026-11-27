#include "chao.h"

namespace TheLastKnights{
namespace Entidades{

Chao::Chao(float x, float y, float largura, float altura): Entidade(x, y),
largura(largura), altura(altura) {
}

Chao::~Chao(){
}


float Chao::getLargura(){
    return largura;
}

float Chao::getAltura(){
    return altura;
}

void Chao::executar() {
    
}

void Chao::salvar() {
    // fazer a salvar depois
    //salvarDataBuffer();
    //buffer << " CHAO";
}


}
}
