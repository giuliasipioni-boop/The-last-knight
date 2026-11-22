#ifndef REI_H
#define REI_H

#include "inimigo.h"
#include "jogador.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

class Jogador;

class Rei : public Inimigo {
private:
    int direcao;

public:
    //construtora e destrutora
    Rei(float x, float y);
    virtual ~Rei();

    void mover();
    void inverterDirecao();
    void lancarProjetil();
    void executar();
    void danificar(Jogador* pJog);
    void salvar();
};

}
}
}

#endif



