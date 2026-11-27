#ifndef _CASTELO_H_
#define _CASTELO_H_
#include "stdafx.h"
#include "fase.h"

namespace TheLastKnights {
namespace Fases{

class Castelo : public Fase {
private:
    const int MaxReis;
    
protected:
    void criarInimigos();
    void criarObstaculos();
    
    void criarReis();
    void criarProjeteis();
    void criarFogueiras();
    
    
public:
    //construtora e destrutora
    Castelo();
    ~Castelo();
    
    void executar();
};

}
}


#endif
