#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_
#include "stdafx.h"
#include "ente.h"


class Entidade : public Ente {
protected:
    int x;
    int y;
    int velX;
    int velY;

    //ostream buffer;

public:
    Entidade(int id, int x, int y);
    virtual ~Entidade();

    void setPosicao(int x, int y);
    void setVelocidade(int velX, int velY);
    int getPosicaoX();
    int getPosicaoY();
    int getVelocidadeX();
    int getVelocidadeY();
    
    //void salvaDataBuffer();
    virtual void executar()=0;
    virtual void salvar()=0;
    
};

#endif
