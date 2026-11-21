#include "inimigo.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Inimigo::Inimigo(float x, float y, int vida, int nivel): Personagem(x, y, vida), nivel_maldade(nivel), pJogador1(0), pJogador2(0) {
}

Inimigo::~Inimigo() {
}

Jogador* Inimigo::escolherAlvo() {

    bool vivo1 = (pJogador1 != 0 && !pJogador1->morto());
    bool vivo2 = (pJogador2 != 0 && !pJogador2->morto());

    if (!vivo1 && !vivo2) {
        return 0;
    }

    if (!vivo1) {
        return pJogador2;
    }

    if (!vivo2) {
        return pJogador1;
    }

    float distancia1 = pJogador1->getPosicaoX() - x;
    float distancia2 = pJogador2->getPosicaoX() - x;

    if (distancia1 < 0.f) {
        distancia1 = -distancia1;
    }

    if (distancia2 < 0.f) {
        distancia2 = -distancia2;
    }

    if (distancia1 <= distancia2) {
        return pJogador1;
    }

    return pJogador2;
}


void Inimigo::setJogadores(Jogador* jog1, Jogador* jog2) {
    pJogador1 = jog1;
    pJogador2 = jog2;
}


}
}
}


