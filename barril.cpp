#include "barril.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Obstaculos {

Barril::Barril(float x, float y):Obstaculo(x, y, false) {
    if (pGG != nullptr) {
        pGG->aplicarTextura(this, "barril");
    }
}

Barril::~Barril() {
}

void Barril::executar(){
    aplicarFisica();
    desenhar();
}

void Barril::salvar(){
}

void Barril::obstaculizar(Personagens::Personagem* pP) {

    if (pP != nullptr) {
        pP->setVelocidade(0.0, pP->getVelocidadeY());
    }
}

}
}
}
