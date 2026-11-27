#ifndef ESQUELETO_H
#define ESQUELETO_H

#include "inimigo.h"
#include "jogador.h"

namespace TheLastKnights {
namespace Entidades {
namespace Personagens {

class Jogador;

class Esqueleto : public Inimigo {
private:
    int direcao;

public:
    //construtora e destrutora
    Esqueleto(float x, float y);
    virtual ~Esqueleto();

    void mover();
    void inverterDirecao();
    void executar();
    void danificar(Jogador* pJog);
    void salvar();

};

}
}
}

#endif

