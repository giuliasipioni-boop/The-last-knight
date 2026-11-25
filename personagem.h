#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_
#include "stdafx.h"
#include "entidade.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {

class Personagem : public Entidade {
protected:
    int vida;
    
    public :
    //construtora e destrutora
    Personagem(float x, float y, int vida);
    virtual ~Personagem();
    
    void setVida(int vida);
    int getVida();
    
    void operator--();
    void Dano();
    bool morto();
    
    void pular();
    
    virtual void executar()=0;
    virtual void salvar()=0;
    virtual void mover()=0;
    
};

}
}
}

#endif 
