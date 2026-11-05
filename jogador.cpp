#include "jogador.h"
#include "gerenciador_grafico.h"

Jogador::Jogador(int x, int y, int num): Personagem(x, y, 5), nJog(num), pontosJog(0){
    if (pGG != nullptr)
    {
        if (nJog == 1)
        {
            pGG->aplicarTextura(this, "jogador1");
        }
        else if (nJog == 2)
        {
            pGG->aplicarTextura(this, "jogador2");
        }
    }
}

Jogador::~Jogador(){

}


void Jogador::mover(){
        if (pGG == nullptr)
            return;

        if (nJog == 1)
            x += pGG->getMovimentoXJog1();

        else if (nJog == 2)
            x += pGG->getMovimentoXJog2();

        figura.setPosition(x, y);
}


void Jogador::executar(){
    mover();
}

void Jogador::salvar(){

    //fazer quando implementarmos o salvamento
    
}
