
#ifndef LISTA_ENTIDADES_H
#define LISTA_ENTIDADES_H

#include "lista.h"
#include "entidade.h"

namespace TrabalhoJogo {
namespace Listas {

class ListaEntidades {
private:
    Lista<Entidades::Entidade> LEs;

    ListaEntidades(const ListaEntidades&);
    ListaEntidades& operator=(const ListaEntidades&);

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidades::Entidade* pE);
    void percorrer();
    void desenhar();
};

}
}

#endif

