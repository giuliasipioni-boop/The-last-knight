#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "obstaculo.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Obstaculos {

class Plataforma : public Obstaculo {
public:
    Plataforma(float x, float y);
    virtual ~Plataforma();

    void executar();
    void salvar();

    void obstaculizar(Personagens::Jogador* pJ);
};

}
}
}

#endif
