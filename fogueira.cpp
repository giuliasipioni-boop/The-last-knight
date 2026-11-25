#include "fogueira.h"
#include "gerenciador_grafico.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Obstaculos {

Fogueira::Fogueira(float x, float y)
    : Obstaculo(x, y, true) {

    if (pGG != nullptr) {
        pGG->aplicarTextura(this, "fogueira");
    }
}

Fogueira::~Fogueira() {
}

void Fogueira::executar() {
    desenhar();
}

void Fogueira::salvar() {
    // Implementar junto ao sistema de salvamento do jogo.
}

void Fogueira::obstaculizar(Personagens::Jogador* pJ) {
    if (pJ == nullptr || pJ->morto()) return;

    pJ->Dano();
}

}
}
}
