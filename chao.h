#ifndef CHAO_H
#define CHAO_H

#include "Plataforma.h"
#include "Entidade.h"

// Chao é uma plataforma fixa que representa o piso da fase.
// É uma extensão do UML original: no diagrama existe Plataforma,
// mas não existe uma classe chamada Chao.
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

#endif
