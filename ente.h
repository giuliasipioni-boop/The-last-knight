#ifndef _ENTE_H_
#define _ENTE_H_
#include "stdafx.h"

class Ente{
protected:
    int id;
    static *Gerenciador_grafico;
    Figura* pFig;

public:
    Ente();
    virtual ~Ente();
    virtual void executar()=0;
    void desenhar();
    void static setGG(Gerenciador_grafico* pG);
    
}


#endif
