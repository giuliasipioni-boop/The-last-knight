#include "lista_entidades.h"
#include "personagem.h"
#include "projetil.h"

namespace TrabalhoJogo {
namespace Listas {

ListaEntidades::ListaEntidades() {
}

ListaEntidades::~ListaEntidades() {
}

void ListaEntidades::incluir(Entidades::Entidade* pE) {
    LEs.incluir(pE);
}

void ListaEntidades::percorrer() {

    Elemento<Entidades::Entidade>* atual =
        LEs.getPrimeiro();

    while (atual != 0) {

        Entidades::Entidade* pE = atual->getInfo();

        if (pE != 0) {
            pE->executar();
        }

        atual = atual->getProx();
    }
}

void ListaEntidades::desenhar() {

    Elemento<Entidades::Entidade>* atual =
        LEs.getPrimeiro();

    while (atual != 0) {

        Entidades::Entidade* pE = atual->getInfo();

        if (pE != 0) {

            bool visivel = true;

            Entidades::Personagens::Personagem* pP =
                dynamic_cast<
                    Entidades::Personagens::Personagem*
                >(pE);

            if (pP != 0 && pP->estaMorto()) {
                visivel = false;
            }

            Entidades::Projetil* pProj =
                dynamic_cast<Entidades::Projetil*>(pE);

            if (pProj != 0 && !pProj->estaAtivo()) {
                visivel = false;
            }

            if (visivel) {
                pE->desenhar();
            }
        }

        atual = atual->getProx();
    }
}

}
}
