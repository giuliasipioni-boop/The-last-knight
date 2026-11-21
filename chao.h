#ifndef CHAO_H
#define CHAO_H

#include "entidade.h"

namespace TrabalhoJogo{
namespace Entidades{


class Chao : public Entidade {
private:
    float largura;
    float altura;
    
public:
    Chao(float x, float y, float largura, float altura);
    virtual ~Chao();
    
    virtual void executar();
    virtual void salvar();
};


}
}
#endif
