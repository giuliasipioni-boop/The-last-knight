#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "obstaculo.h"
#include "personagem.h"

namespace TheLastKnights {
namespace Entidades {
namespace Obstaculos {

class Plataforma : public Obstaculo {
private:
    float empuxo;

public:
    Plataforma(float x, float y);
    virtual ~Plataforma();

    void executar();
    void salvar();
    void aplicarFisica();
    
    void obstaculizar(Personagens::Personagem* pP);
    
};

}
}
}

#endif
