#ifndef CHAO_H
#define CHAO_H

#include "Entidade.h"

class Chao : public Entidade {
public:
    Chao(float x, float y, float largura, float altura);
    virtual ~Chao();

    virtual void executar();
    virtual void salvar();
};

#endif
