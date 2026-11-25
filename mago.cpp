#include "mago.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

Mago::Mago(float x, float y): Inimigo(x, y, 2, 2), direcao(-1){
    velX = -80.0;

    if (pGG != 0) {
        pGG->aplicarTextura(this, "mago");
    }
}

Mago::~Mago() {
}


//revisar
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
    
    velX = 80.0 * direcao;
    
    
    if (velX < 0.0) {
        virar(false);
    }
    else if (velX > 0.0) {
        virar(true);
    }

    aplicarFisica();
}

void Mago::inverterDirecao() {
    direcao *= -1;
    
}

void Mago::executar() {
    if (!morto()) {
        mover();

    }
}

void Mago::danificar(Jogador* pJog){
    if (pJog != 0 && !morto()) {
        if (!pJog->morto()) {
            pJog->Dano();
        }
    }
}

void Mago::salvar(){
    //fazer salvamento dps
}

}
}
}

