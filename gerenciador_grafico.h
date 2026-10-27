#ifndef _GERENCIADOR_GRAFICO_H_
#define _GERENCIADOR_GRAFICO_H_
#include "stdafx.h"

class Gerencidor_grafico {
private:
    BiblioGrafica obj;

public:
    Gerenciador_grafico ();
    ~Gerenciador_grafico();
    desenharEnte(Ente *pE);
    
}


#endif

