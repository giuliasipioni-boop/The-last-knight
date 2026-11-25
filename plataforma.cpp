#include "plataforma.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Obstaculos {

Plataforma::Plataforma(float x, float y):
    Obstaculo(x, y, false), empuxo(gravidade) {

    if (pGG != nullptr) {
        pGG->aplicarTextura(this, "plataforma");
    }
}

Plataforma::~Plataforma() {
}

void Plataforma::executar() {
    aplicarFisica();
    desenhar();
}

void Plataforma::salvar() {
}

void Plataforma::aplicarFisica() {

    x += velX * tempo;

    velY += (gravidade - empuxo) * tempo;
    y += velY * tempo;

    figura.setPosition(x, y);
}


}
}
}
