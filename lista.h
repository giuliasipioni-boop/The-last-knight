#ifndef LISTA_H
#define LISTA_H

#include "elemento.h"

namespace TrabalhoJogo {
namespace Listas {

template<class TL>
class Lista {
private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

    Lista(const Lista<TL>&);
    Lista<TL>& operator=(const Lista<TL>&);

public:
    Lista()
        : pPrimeiro(0), pUltimo(0) {
    }

    ~Lista() {
        limpar();
    }

    void incluir(TL* pE) {

        if (pE == 0) {
            return;
        }

        Elemento<TL>* novo = new Elemento<TL>(pE);

        if (pPrimeiro == 0) {
            pPrimeiro = novo;
            pUltimo = novo;
        }
        else {
            pUltimo->setProx(novo);
            pUltimo = novo;
        }
    }

    Elemento<TL>* getPrimeiro() const {
        return pPrimeiro;
    }

    void limpar() {

        Elemento<TL>* atual = pPrimeiro;

        while (atual != 0) {
            Elemento<TL>* proximo = atual->getProx();

            delete atual;
            atual = proximo;
        }

        pPrimeiro = 0;
        pUltimo = 0;
    }
};

}
}

#endif

