#include "mago.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Mago::Mago(float x, float y): Inimigo(x, y, 2, 2), direcao(-1),{
    velX = -110.f;

    if (pGG != 0) {
        pGG->aplicarTextura(this, "mago");
    }
}

Mago::~Mago() {
}

void Mago::mover() {

    Jogador* alvo = escolherAlvo();

    if (alvo != 0) {

        if (alvo->getPosicaoX() > x) {
            direcao = 1;
        }
        else if (alvo->getPosicaoX() < x) {
            direcao = -1;
        }
        else {
            direcao = 0;
        }

    }
    else {
        direcao = 0;
    }

    velX = 110.f * direcao;

    aplicarFisica();
}

void Mago::inverterDirecao() {
    direcao *= -1;
}

}
}
}

