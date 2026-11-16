#ifndef INIMIGO_H
#define INIMIGO_H

#include "personagem.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

class Jogador;

class Inimigo : public Personagem {
protected:
    int nivel_maldade;
    Jogador* pJogador1;
    Jogador* pJogador2;

    Jogador* escolherAlvo();

public:
    //construtora e destrutora
    Inimigo(float x, float y, int vida, int nivel);
    virtual ~Inimigo();

    virtual void danificar(Jogador* pJog);
    void setJogadores(Jogador* jog1, Jogador* jog2);

    virtual void mover() = 0;
    virtual void executar();
    virtual void salvar();
};

}
}
}

#endif

