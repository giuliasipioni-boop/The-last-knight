#include "esqueleto.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Esqueleto::Esqueleto(float x, float y): Inimigo(x, y, 1, 1), direcao(1) {
    velX = 80.f;

    if (pGG != 0) {
        pGG->aplicarTextura(this, "esqueleto");
    }
}

Esqueleto::~Esqueleto() {
}

void Esqueleto::mover() {

    velX = 80.f * direcao;

    aplicarFisica();

}

void Esqueleto::inverterDirecao() {
    direcao *= -1;
}


}
}
}

