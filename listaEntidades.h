
#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H

#include "lista.h"
#include "entidade.h"

namespace TrabalhoJogo {
namespace Listas {

class ListaEntidades {
//codigo do Peteco
private:
    Lista<Entidades::Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidades::Entidade* pE);
    void remover(Entidades::Entidade* pE);
    void remover(size_t indice);
    size_t getTamanho() const;

    // Também inspirada na implementação do Burda,
    // vide vídeo 8 da playlist Tutorial Jogo SFML,
    // como no header "Lista.h", naturalmente.
    Entidades::Entidade* operator[](int indice) const;

    void limpar();
    void percorrer(); // Lista elemento por elemento (template).
    void executar(); // Chama executar de cada Entidade.

    void salvar(std::ostream* arquivo);
};

}
}

#endif

