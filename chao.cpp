#include "Chao.h"

namespace TrabalhoJogo{
namespace Entidades{

Chao::Chao(float x, float y, float largura, float altura)
: Entidade(x, y) {
}

Chao::~Chao() {
}

void Chao::executar() {
    // O chao e fixo: nao precisa atualizar sua posicao.
}

void Chao::salvar() {
    // fazer a salvar depois
    //salvarDataBuffer();
    //buffer << " CHAO";
}


}
}
