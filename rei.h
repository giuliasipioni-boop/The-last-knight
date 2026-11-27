#ifndef REI_H
#define REI_H

#include "inimigo.h"
#include "jogador.h"
#include "projetil.h"

namespace TheLastKnights {
namespace Entidades {
namespace Personagens {

class Jogador;

class Rei : public Inimigo {
private:
    int direcao;
    bool lancouProjetil;
    Projetil* pProj;
    float tempoLancamento;

public:
    //construtora e destrutora
    Rei(float x, float y);
    virtual ~Rei();

    void mover();
    void inverterDirecao();
    
    Projetil* getProjetil();
    void lancarProjetil();
    
    void executar();
    void danificar(Jogador* pJog);
    void salvar();
};

}
}
}

#endif



