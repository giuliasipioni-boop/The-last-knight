#include "rei.h"
#include "jogador.h"
#include "gerenciador_grafico.h"

namespace TheLastKnights {
namespace Entidades {
namespace Personagens {

Rei::Rei(float x, float y): Inimigo(x, y, 3, 3), direcao(1), lancouProjetil(false), tempoLancamento(-1.0) {

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
    
    velX *=direcao;
    
    if (velX < 0.0) {
        virar(false);
    }
    else if (velX > 0.0) {
        virar(true);
    }

    aplicarFisica();
}

void Rei::inverterDirecao() {
    direcao *= -1;
}

Projetil* Rei::getProjetil() {
    return pProj;
}

void Rei::lancarProjetil() {

    if (!lancouProjetil) {

        sf::Vector2f vetorX(350.0 * direcao, 0.0);
        sf::Vector2f vetorY(0.0, -500.0);

        // Soma vetorial
        sf::Vector2f resultante = vetorX + vetorY;

        pProj = new Projetil(x, y, resultante.x, resultante.y);

        lancouProjetil = true;
    }
}

void Rei::executar(){
    if (!morto()) {
        velX = 60.0;
        mover();
        
        if (!lancouProjetil) {
            if (tempoLancamento == -1.0) {
                tempoLancamento = 3 + rand() % 8;
            }
            
            tempoLancamento -= tempo;
            
            if (tempoLancamento <= 0.0) {
                lancarProjetil();
            }
        }
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



