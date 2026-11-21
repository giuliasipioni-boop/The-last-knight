
#ifndef MAGO_H
#define MAGO_H

#include "inimigo.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

class Jogador;

class Mago : public Inimigo {
private:
    int direcao;

public:
    //construtora e destrutora
    Mago(float x, float y);
    virtual ~Mago();

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

