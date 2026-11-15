#include "jogador.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Jogador::Jogador(float x, float y, int num) : Personagem(x, y, 5), nJog(num),pontosJog(0),direcao(0) {

    if (pGG != 0) {
        if (nJog == 1) {
            pGG->aplicarTextura(this, "jogador1");
        }
        else if (nJog == 2) {
            pGG->aplicarTextura(this, "jogador2");
        }
    }
}

Jogador::~Jogador() {
}

void Jogador::setDirecao(int direcao) {
    this->direcao = direcao;
    velX = 250.f * direcao;
}

void Jogador::atacar() {
    // ataque com espada

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
]
