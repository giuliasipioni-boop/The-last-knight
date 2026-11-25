#include "barril.h"
#include "gerenciador_grafico.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Obstaculos {

Barril::Barril(float x, float y)
    : Obstaculo(x, y, false) {

    if (pGG != nullptr) {
        pGG->aplicarTextura(this, "barril");
    }
}

Barril::~Barril() {
}

void Barril::executar() {
    desenhar();
}

void Barril::salvar() {
    // Implementar junto ao sistema de salvamento do jogo.
}

void Barril::obstaculizar(Personagens::Jogador* pJ) {
    if (pJ == nullptr || pJ->morto()) return;

    sf::FloatRect barril =
        static_cast<const sf::Sprite&>(getFigura()).getGlobalBounds();

    sf::FloatRect jogador =
        static_cast<const sf::Sprite&>(pJ->getFigura()).getGlobalBounds();

    float fundoJogador = jogador.top + jogador.height;

    if (pJ->getVelocidadeY() >= 0.0f &&
        pJ->getYAnterior() + jogador.height <= barril.top + 5.0f) {

        if (fundoJogador >= barril.top) {
            pJ->pousar(
                pJ->getPosicaoY() + barril.top - fundoJogador
            );
        }
    }
}

}
}
}
