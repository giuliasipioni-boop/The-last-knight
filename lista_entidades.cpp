#include "lista_entidades.h"
#include "personagem.h"
#include "projetil.h"

namespace TrabalhoJogo {
namespace Listas {

ListaEntidades::ListaEntidades(){
}

ListaEntidades::~ListaEntidades(){
    limpar();
}

void ListaEntidades::limpar(){
    LEs.limpar();
}

void ListaEntidades::incluir(Entidades::Entidade* pE){
    if (pE == nullptr)
        std::cerr << "Ponteiro de entidade nulo! Nao incluido!" << std::endl;

    else
        LEs.incluir(pE);
}

void ListaEntidades::remover(Entidades::Entidade* pE)
{
    if (pE == nullptr)
        std::cerr << "Ponteiro para o qual se solicita remocao (por informacao) eh nulo!" << std::endl;

    else
        LEs.remover(pE);
}

void ListaEntidades::remover(size_t indice){
    LEs.remover(indice);
}

size_t ListaEntidades::getTamanho() const{
    return LEs.getTamanho();
}

Entidades::Entidade* ListaEntidades::operator[](int indice) const{
    return LEs[indice];
}

// Lista elemento por elemento (template).
void ListaEntidades::percorrer(){
    LEs.percorrer();
}

// Chama executar de cada Entidade.
void ListaEntidades::executar() {
    const int tamanho = static_cast<int>(getTamanho());

    for (int i = 0; i < tamanho; i++) {
        if (LEs[i] != nullptr) {
            LEs[i]->executar();
        }
    }
}
 

/*void ListaEntidades::salvar(std::ostream* arquivo)
{
    const int tamanho = static_cast<int>(getTamanho());
    for (int i = 0; i < tamanho; i++)
    {
        LEs[i]->setBuffer(arquivo);
        LEs[i]->salvar();
        LEs[i]->setBuffer(nullptr);
    }
}*/


}
}
