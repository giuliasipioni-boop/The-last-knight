#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_
#include "stdafx.h"
#include "ente.h"

namespace TrabalhoJogo {
namespace Entidades {

class Entidade : public TrabalhoJogo::Ente {
protected:
    float x;
    float y;
    float velX;
    float velY;
    
public:
    Entidade(float x, float y);
    virtual ~Entidade();
    
    void setPosicao(float x, float y);
    void setVelocidade(float velX, float velY);
    int getPosicaoX();
    int getPosicaoY();
    int getVelocidadeX();
    int getVelocidadeY();
    
    virtual void executar()=0;
    virtual void salvar()=0;
    
};

}
}

#endif
