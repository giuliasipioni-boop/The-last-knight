#include "rei.h"
#include "jogador.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Rei::Rei(float x, float y): Inimigo(x, y, 3, 3), direcao(1) {
    velX = -65.0;

    if (pGG != 0) {
        pGG->aplicarTextura(this, "rei");
    }
}

Rei::~Rei() {
}


//revisar
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

    velX = 60.0 * direcao;

    aplicarFisica();
}

void Rei::inverterDirecao() {
    direcao *= -1;
}

void Rei::lancarProjetil() {
    
}

void Rei::executar(){
    if (!morto()) {
        mover();
    }
}

void Rei::danificar(Jogador* pJog){
    if (pJog != 0 && !morto()) {
        if (!pJog->morto()) {
            pJog->Dano();
        }
    }
}

void Rei::salvar(){
    //fazer salvamento dps
}


}
}
}



