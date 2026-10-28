#ifndef _GERENCIADOR_COLISOES_H_
#define _GERENCIADOR_COLISOES_H_
#include "stdafx.h"

class Gerenciador_colisoes{
private:
    vector <Inimigo*> LIs;
    list <Obstaculo*> LOs;
    set <Projetil*> LPs;
    Jogador *pJog1;
    Jogador *pJog2;

    const bool verificarColisoes(Entidade* pe1, Entidade* pe2) const;
    void tratar_colisoes_JogXObs();
    void tratar_colisoes_JogXInim();
    void tratar_colisoes_JogXProjet();
    
public:
    incluirInimigo(Inimigo* pI);
    incluirObstaculo(Obstaculo* pO);
    incluirProjetil(Projetil* pP);
    void executar();
    
}

#endif

