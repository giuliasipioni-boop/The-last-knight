#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_
#include "stdafx.h"
#include "entidade.h"

class Personagem : public Entidade {
protected:
    int vida;

public :
    Personagem(int x, int y, int vida);
    virtual ~Personagem();

    void setVida(int vida);
    int getVida();

    void Dano();
    virtual void executar()=0;
    virtual void salvar()=0;
    virtual void mover()=0;

};

#endif 
