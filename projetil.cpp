#include "projetil.h"
#include "gerenciador_grafico.h"

namespace TheLastKnights {
namespace Entidades {

Projetil::Projetil(float x, float y, float velX, float velY): Entidade(x, y), ativo(true), associado(false){

    setVelocidade(velX, velY);

    if (pGG != 0) {
        pGG->aplicarTextura(this, "projetil");
    }
}

Projetil::~Projetil() {
}

bool Projetil::estaAtivo() const {
    return ativo;
}

void Projetil::desativar() {
    ativo = false;
}

bool Projetil::estaAssociado() const{
    return associado;
}

void Projetil::setAsssociado(bool associado){
    this->associado = associado;
}

void Projetil::executar() {
    if (ativo)
        aplicarFisica();
}


void Projetil::salvar() {
    // Implementar quando fizermos o salvamento.
}

void Projetil::danificar(Personagens::Jogador* pJ) {

    if (ativo && pJ != nullptr && !pJ->morto()) {
        
        pJ->Dano();
        desativar();
    }
}


}
}

