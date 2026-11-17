
#ifndef JOGO_H
#define JOGO_H

#include "gerenciador_grafico.h"
#include "jogador.h"

namespace TrabalhoJogo {

class Jogo {
private:
    Gerenciadores::Gerenciador_grafico grafico;

    Entidades::Personagens::Jogador* pJog1;

public:
    Jogo();
    ~Jogo();

    void executar();
};

}

#endif
