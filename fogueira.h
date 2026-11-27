#ifndef _FOGUEIRA_H_
#define _FOGUEIRA_H_

#include "obstaculo.h"
#include "personagem.h"


namespace TheLastKnights {
namespace Entidades {
namespace Obstaculos {

class Fogueira : public Obstaculo {
public:
    Fogueira(float x, float y);
    virtual ~Fogueira();

    void executar();
    void salvar();

    void obstaculizar(Personagens::Personagem* pP);
};

}
}
}

#endif
