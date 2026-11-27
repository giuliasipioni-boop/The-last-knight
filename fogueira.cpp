#include "fogueira.h"
#include "gerenciador_grafico.h"
#include "jogador.h"

namespace TheLastKnights {
namespace Entidades {
namespace Obstaculos {

Fogueira::Fogueira(float x, float y): Obstaculo(x, y, true) {
    if (pGG != nullptr) {
        pGG->aplicarTextura(this, "fogueira");
    }
}

Fogueira::~Fogueira() {
}

void Fogueira::executar(){
    aplicarFisica();
    if (rand() % 10000000 == 1){
        danoso = false;
    }
}

void Fogueira::salvar() {
    // Implementar junto ao sistema de salvamento do jogo.
}

void Fogueira::obstaculizar(Personagens::Personagem* pP) {

    if (pP != nullptr && !pP->morto()) {

        pP->setVelocidade(0.0, pP->getVelocidadeY());

        if (ehDanoso()) {
            Personagens::Jogador* pJ = dynamic_cast<Personagens::Jogador*>(pP);

            if (pJ != nullptr) {
                pJ->Dano();
            }
        }
    }
}

}
}
}
