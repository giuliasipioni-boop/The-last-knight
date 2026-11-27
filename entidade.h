#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_
#include "stdafx.h"
#include "ente.h"

namespace TheLastKnights {
namespace Entidades {

class Entidade : public Ente {
protected:
    float x;
    float y;
    float velX;
    float velY;
    float tempo;
    float gravidade;
    bool noAr;
    
public:
    Entidade(float x, float y);
    virtual ~Entidade();
    
    void setPosicao(float x, float y);
    void setVelocidade(float velX, float velY);
    float getPosicaoX();
    float getPosicaoY();
    float getVelocidadeX();
    float getVelocidadeY();
    void setTempo(float tempo);
    void pousar(float posY);
    virtual void aplicarFisica();
    
    virtual void executar()=0;
    virtual void salvar()=0;
    
};

}
}

#endif
