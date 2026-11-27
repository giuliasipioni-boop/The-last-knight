#include "esqueleto.h"
#include "gerenciador_grafico.h"

namespace TheLastKnights {
namespace Entidades {
namespace Personagens {

Esqueleto::Esqueleto(float x, float y): Inimigo(x, y, 1, 1), direcao(-1) {

    if (pGG != 0) {
        pGG->aplicarTextura(this, "esqueleto");
    }
    
    virar(false);
    
}

Esqueleto::~Esqueleto() {
}

void Esqueleto::mover() {

    velX *= direcao;
    aplicarFisica();

}

void Esqueleto::inverterDirecao() {
    direcao *= -1;
    virar(direcao == 1);
}

void Esqueleto::executar(){
    if (!morto()) {
        velX = 60.0;
        mover();
    }
}

void Esqueleto::danificar(Jogador* pJog){
    if (pJog != 0 && !morto()) {
        if (!pJog->morto()) {
            pJog->Dano();
        }
    }
}

void Esqueleto::salvar(){/*
    arquivo << id << " Esqueletos " << getVida()
            << " " << getPosicaoX()
            << " " << getPosicaoY()
            << " " << getVelocidadeX()
            << "\n";*/
}

}
}
}

