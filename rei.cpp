#include "rei.h"
#include "jogador.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Rei::Rei(float x, float y): Inimigo(x, y, 3, 3), direcao(1) {
    velX = 65.f;

    if (pGG != 0) {
        pGG->aplicarTextura(this, "rei");
    }
}

Rei::~Rei() {
}

void Rei::mover() {

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

    velX = 65.f * direcao;

    aplicarFisica();
}

void Rei::inverterDirecao() {
    direcao *= -1;
}

void Rei::lancarProjetil() {
    
}
    

}
}
}



