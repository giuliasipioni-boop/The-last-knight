#ifndef PROJETIL_H
#define PROJETIL_H

#include "entidade.h"
#include "jogador.h"

namespace TheLastKnights {
namespace Entidades {

namespace Pesonagens{
class Jogador;
}

class Projetil : public Entidade {
private:
    bool ativo;
    bool associado;

public:
    Projetil(float x, float y, float velX, float velY);
    virtual ~Projetil();

    bool estaAtivo() const;
    void desativar();
    bool estaAssociado() const;
    void setAsssociado(bool associado);

    void executar();
    void salvar();
    void danificar(Personagens::Jogador* pJ);
};

}
}

#endif
