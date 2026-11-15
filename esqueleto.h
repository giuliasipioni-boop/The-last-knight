#ifndef ESQUELETO_H
#define ESQUELETO_H

#include "inimigo.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

class Esqueleto : public Inimigo {
private:
    int direcao;

public:
    //construtora e destrutora
    Esqueleto(float x, float y);
    virtual ~Esqueleto();

    void mover();
    void inverterDirecao();
};

}
}
}

#endif

