#ifndef _JOGADOR_H_
#define _JOGADOR_H_
#include "stdafx.h"
#include "personagem.h"

namespace TrabalhoJogo {
namespace Entidades {
namespace Personagens {


class Jogador : public Personagem{
private:
    int nJog;
    int pontosJog;
    int direcao;
    
public:
    //construtora e destrutora
    Jogador(float x, float y, int num);
    virtual ~Jogador();
    
    void setDirecao(int direcao);
    void atacar();
    void mover();
    void executar();
    void salvar();
    //void colidir(Inimigo* pIni);
    
};

}
}
}



#endif
