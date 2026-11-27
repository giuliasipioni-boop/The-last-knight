#include "stdafx.h"
#include "jogo.h"

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    TheLastKnights::Jogo jogo;
    jogo.executar();

    return 0;
}
