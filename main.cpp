#include "stdafx.h"
#include "jogo.h"

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    TrabalhoJogo::Jogo jogo;
    jogo.executar();

    return 0;
}
