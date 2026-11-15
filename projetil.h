#ifndef PROJETIL_H
#define PROJETIL_H

#include "entidade.h"

namespace TrabalhoJogo {
namespace Entidades {

class Projetil : public Entidade {
private:
    bool ativo;
    float tempo;
    float gravidade;

public:
    Projetil(float x, float y, float velX, float velY);
    virtual ~Projetil();

    void setTempo(float tempo);
    bool estaAtivo() const;
    void desativar();

    void executar();
    void salvar();
};

}
}

#endif
