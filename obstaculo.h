#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "entidade.h"

namespace TheLastKnights{
namespace Entidades{
namespace Personagens{
class Personagem;
}

namespace Obstaculos{

class Obstaculo : public Entidade {
protected:
    bool danoso;
    
public:
    Obstaculo(float x, float y, bool danoso);
    virtual ~Obstaculo();
    
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void obstaculizar(Personagens::Personagem* pP) = 0;
    
    bool ehDanoso() const;
};

}
}
}
#endif
