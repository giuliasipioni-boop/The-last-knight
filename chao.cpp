#include "Chao.h"

Chao::Chao(float x, float y, float largura, float altura)
    : Plataforma(),
      larguraChao(largura),
      alturaChao(altura) {

    setPosicao(x, y);
    definirTamanho(largura, altura);
}

Chao::~Chao() {
}

void Chao::executar() {
    // O chão é fixo: não precisa se mover nem atualizar sua posição.
    // A colisão/aterrissagem é tratada pela física de Entidade.
}

PlataformaFisica Chao::getLimitesFisicos() const {
    return PlataformaFisica(
        getX(),
        getY(),
        larguraChao,
        alturaChao
    );
}
