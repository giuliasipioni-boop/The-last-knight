#ifndef CHAO_H
#define CHAO_H

#include "plataforma.h"
#include "entidade.h"


namespace TrabalhoJogo {
namespace Entidades{

class Chao : public Plataforma {
private:
    float larguraChao;
    float alturaChao;
    
public:
    Chao(float x, float y, float largura, float altura);
    virtual ~Chao();
    
    virtual void executar();
    
    // Retorna os limites do chão no formato usado pela física de Entidade.
    PlataformaFisica getLimitesFisicos() const;
};

}
}

#endif

