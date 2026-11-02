#ifndef _JOGADOR_H_
#define _JOGADOR_H_
#include "stdafx.h"
#include "personagem.h"


class Jogador : public Personagem{
    private:
    int nJog;
    int pontosJog;

    public:
    Jogador(int id, int x, int y, int num);
    virtual ~Jogador();
    void mover();
    void executar();
    void salvar();
    //void colidir(Inimigo* pIni);

};



#endif