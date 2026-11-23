#ifndef _CASTELO_H_
#define _CASTELO_H_
#include "stdafx.h"
#include "fase.h"

namespace TrabalhoJogo {
namespace Fases{

class Castelo : public Fase {
private:
    const int MaxReis;
    
public:
    //construtora e destrutora
    Castelo();
    ~Castelo();
    
    void criarInimigos();
    void criarObstaculos();
    
    void criarReis();
    void criarFogueiras();
    
    void executar();
};

}
}


#endif
