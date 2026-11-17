#ifndef JOGO_H
#define JOGO_H

#include "gerenciador_grafico.h"

namespace TrabalhoJogo {

class Jogo {
private:
    Gerenciadores::Gerenciador_grafico grafico;

public:
    Jogo();
    ~Jogo();

    void executar();
};

}

#endif
