#ifndef _FOGUEIRA_H_
#define _FOGUEIRA_H_

#include "obstaculo.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Obstaculos {

class Fogueira : public Obstaculo {
public:
    Fogueira(float x, float y);
    virtual ~Fogueira();

    void executar();
    void salvar();

    void obstaculizar(Personagens::Jogador* pJ);
};

}
}
}

#endif
