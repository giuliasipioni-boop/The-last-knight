#include "projetil.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {

Projetil::Projetil(float x, float y, float velX, float velY): Entidade(x, y), ativo(true), tempo(0.f), gravidade(500.f) {

    setVelocidade(velX, velY);

    if (pGG != 0) {
        pGG->aplicarTextura(this, "projetil");
    }
}

Projetil::~Projetil() {
}

void Projetil::setTempo(float tempo) {
    this->tempo = tempo;
}

bool Projetil::estaAtivo() const {
    return ativo;
}

void Projetil::desativar() {
    ativo = false;
}

void Projetil::executar() {

    if (!ativo) {
        return;
    }

    x += velX * tempo;

    velY += gravidade * tempo;
    y += velY * tempo;

    figura.setPosition(x, y);

    //figura.rotate(300.f * tempo);
}

void Projetil::salvar() {
    // Implementar quando fizermos o salvamento.
}

}
}

