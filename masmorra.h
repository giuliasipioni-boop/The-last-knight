#ifndef _PRIMEIRAFASE_H_
#define _PRIMEIRAFASE_H_
#include "stdafx.h"
#include "fase.h"

namespace TrabalhoJogo {
namespace Fases{

class Masmorra : public Fase {
private:
    const int MaxMagos;
    
protected:
    void criarInimigos();
    void criarObstaculos();
    
    void criarMagos();
    void criarBarril();
    
public:
    //construtora e destrutora
    Masmorra();
    ~Masmorra();
    
    void executar();
};

}
}

#endif
