
#ifndef _JOGO_H_
#define _JOGO_H_

#include "stdafx.h"
#include "gerenciador_grafico.h"
#include "gerenciador_eventos.h"
#include "jogador.h"
#include "masmorra.h"
#include "castelo.h"

namespace TrabalhoJogo {

class Jogo {
private:
    Gerenciadores::Gerenciador_grafico GG;
    Gerenciadores::Gerenciador_eventos* GE;

    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;

    Fases::Masmorra* pMasmorra;
    Fases::Castelo* pCastelo;

    sf::Clock relogio;

public:
    Jogo();
    ~Jogo();

    void executar();
};

}

#endif

