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
    int direcao;
    bool atacando;
    int ladoAtaque;
    
public:
    //construtora e destrutora
    Jogador(float x, float y, int num);
    virtual ~Jogador();
    
    void setDirecao(int direcao);
    void setAtacando(bool atacando);
    bool estaAtacando() const;
    int getLadoAtaque() const;
    void mover();
    void executar();
    void salvar();
    
    
};

}
}
}



#endif
