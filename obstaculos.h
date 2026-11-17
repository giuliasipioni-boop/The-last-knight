#ifndef _OBSTACULOS_H_
#define _OBSTACULOS_H_

#include "Entidade.h"
namespace TrabalhoJogo{
namespace Entidades{
namespace Obstaculos{

class Obstaculos : public Entidade {
protected:
    bool danoso;
    
public:
    Obstaculos(float x, float y, bool danoso);
    virtual ~Obstaculos();
    
    virtual void executar() = 0;
    virtual void salvar() = 0;
    
    bool ehDanoso() const;
};

}
}
}
#endif
