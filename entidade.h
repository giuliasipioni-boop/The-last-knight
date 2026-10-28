#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_
#include "stdafx.h"


class Entidade :: Public Ente {
protected:
    int x;
    int y;
    ostream buffer;

public:
    Entidade();
    virtual ~Entidade();
    void salvaDataBuffer();
    virtual void executar()=0;
    virtual void salvar()=0;
    
}

#endif
