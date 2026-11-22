#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "Entidade.h"
namespace TrabalhoJogo{
namespace Entidades{
namespace Obstaculos{

class Obstaculo : public Entidade {
protected:
    bool danoso;
    
public:
    Obstaculo(float x, float y, bool danoso);
    virtual ~Obstaculo();
    
    virtual void executar() = 0;
    virtual void salvar() = 0;
    
    bool ehDanoso() const;
};

}
}
}
#endif
