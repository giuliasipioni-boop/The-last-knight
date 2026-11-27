#ifndef INIMIGO_H
#define INIMIGO_H

#include "personagem.h"

namespace TheLastKnights {
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
    
    void setJogadores(Jogador* jog1, Jogador* jog2);
    //void salvarDataBuffer(std::ofstream& arquivo);

    virtual void mover() = 0;
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void danificar(Jogador* pJog)=0;
};

}
}
}

#endif

