#include "jogador.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Jogador::Jogador(float x, float y, int num) : Personagem(x, y, 5), nJog(num),direcao(1),atacando(false), ladoAtaque(direcao){
    
    if (pGG != 0) {
        if (nJog == 1) {
            pGG->aplicarTextura(this, "jogador1");
        }
        else if (nJog == 2) {
            pGG->aplicarTextura(this, "jogador2");
        }
    }
}

Jogador::~Jogador(){
}

void Jogador::setDirecao(int direcao){

    this->direcao = direcao;
    velX = 250.0f * direcao;

    if (direcao < 0) {
        ladoAtaque = -1;
        virar(false);
    }
    else if (direcao > 0) {
        ladoAtaque = 1;
        virar(true);
    }
}

void Jogador::setAtacando(bool atacando) {
    this->atacando = atacando;
}

bool Jogador::estaAtacando() const {
    return atacando;
}

int Jogador::getLadoAtaque() const {
    return ladoAtaque;
}

void Jogador::mover() {
    aplicarFisica();
}


void Jogador::executar() {
    if (!morto()) {
        mover();
    }
}

void Jogador::salvar() {
    // fazer o salvamento depois
}


}
}
}

