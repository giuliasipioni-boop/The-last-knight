#ifndef REI_H
#define REI_H

#include "inimigo.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

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
};

}
}
}

#endif


#endif

