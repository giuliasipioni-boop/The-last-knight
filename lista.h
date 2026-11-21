#ifndef LISTA_H
#define LISTA_H

#include "stdafx.h"


namespace TrabalhoJogo {
namespace Listas {

//Codigo do PETECO 
template <class TL>
class Lista{
private:
    template <class TE>
    class Elemento{
    private:
        Elemento<TE>* pProx;
        TE* pInfo;

    public:
        Elemento();
        ~Elemento();
                        
        void setElProx(Elemento<TE>* pE);
        Elemento<TE>* getElProx() const;
                        
        // Incluir implementado equivalente a um setInfo().
        void incluir(TE* p);
        TE* getInfo() const;

    };

private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;
    size_t tamanhoLista;

    public:
    Lista();
    ~Lista();
                
    size_t getTamanho() const;
                
    // Inspiração na implementação do Burda,
    // vide vídeo 8 da playlist Tutorial Jogo SFML.
    TL* operator[](int indice) const;

    void remover(int id);
    void remover(TL* pinfo);

    void incluir(TL* p);
    void percorrer();
    void limpar();
};

// Implementação do template Elemento (TE) //

template <class TL>
template <class TE>

Lista<TL>::Elemento<TE>::Elemento():pProx(nullptr),pInfo(nullptr){
    
}

template <class TL>
template <class TE>

Lista<TL>::Elemento<TE>::~Elemento(){
    pProx = nullptr;
    pInfo = nullptr;
}

template <class TL>
template <class TE>
void Lista<TL>::Elemento<TE>::setElProx(Elemento<TE>* pE){
    pProx = pE;
}

template <class TL>
template <class TE>

// Para que o compilador interprete como declaração.
typename Lista<TL>::template Elemento<TE>*
Lista<TL>::Elemento<TE>::getElProx() const{
    return pProx;
}

template <class TL>
template <class TE>

void Lista<TL>::Elemento<TE>::incluir(TE* p){
    if (p == nullptr)
        std::cerr << "Ponteiro TE nulo! Nao incluido!" << std::endl;

    else
        pInfo = p;
}

template <class TL>
template <class TE>

TE* Lista<TL>::Elemento<TE>::getInfo() const{
    return pInfo;
}

// Implementação do template Lista (TL) //
template <class TL>
Lista<TL>::Lista():pPrimeiro (nullptr),pUltimo (nullptr),tamanhoLista (0){
    
}

template <class TL>
Lista<TL>::~Lista(){
    limpar();
    pPrimeiro = nullptr;
    pUltimo = nullptr;
    tamanhoLista = -1;
}

template <class TL>
void Lista<TL>::incluir(TL* p){
    if (p == nullptr){
        std::cerr << "Ponteiro TL nulo! Nao incluido!" << std::endl;
    }
    else{
        Elemento<TL>* pAux = nullptr;
        pAux = new Elemento<TL>();

        pAux->incluir(p);
        if (pPrimeiro == nullptr){
            pPrimeiro = pAux;
            pUltimo = pAux;
        }
        else{
            pUltimo->setElProx(pAux);
            pUltimo = pAux;
        }

        tamanhoLista++;
    }
}

template <class TL>
void Lista<TL>::limpar(){
    Elemento<TL>* pAux = nullptr;

    while(pPrimeiro != nullptr){
        pAux = pPrimeiro->getElProx();
        delete pPrimeiro;
        pPrimeiro = pAux;
    }

    pUltimo = nullptr;
    tamanhoLista = 0;
}

template <class TL>
TL* Lista<TL>::operator[] (int indice) const{
    if (indice < 0 || indice >= tamanhoLista)
        return nullptr;

    Elemento<TL>* pAux = pPrimeiro;
    int i = 0;
    while (i < indice){
        pAux = pAux->getElProx();
        i++;
    }

    return pAux->getInfo();
}

template <class TL>
size_t Lista<TL>::getTamanho() const{
    return tamanhoLista;
}

// Sobrecarga pertinente de método remover.
template <class TL>
void Lista<TL>::remover(int indice){
    if (indice < 0 || indice >= tamanhoLista)
        return;

    Elemento<TL>* pAnte = NULL;
    Elemento<TL>* pAtual = pPrimeiro;

    TL* info = pAtual->getInfo();

    int i = 0;
    while (i < indice){
        pAnte = pAtual;
        pAtual = pAnte->getElProx();
        i++;
    }

    if (pAtual == pPrimeiro){
        pPrimeiro = pAtual->getElProx();
    }

    else if (pAtual == pUltimo){
        pAnte->setElProx(NULL);
        pUltimo = pAnte;
    }

    else{
        pAnte->setElProx(pAtual->getElProx());
    }

    tamanhoLista--;
    delete pAtual;
}

template <class TL>
void Lista<TL>::remover(TL* pinfo){

    if(pPrimeiro == nullptr) {
        return; // Lista vazia.
    }
    Elemento<TL>* pAnte = nullptr;
    Elemento<TL>* pAtual = pPrimeiro;

    TL* info = pAtual->getInfo();

    while (pAtual != nullptr && pAtual->getInfo() != pinfo){
                pAnte = pAtual;
                pAtual = pAnte->getElProx();
    }

    if (pAtual == nullptr)
        return;

    if (pAtual == pPrimeiro){
        pPrimeiro = pAtual->getElProx();
    }

    else if (pAtual == pUltimo){
        pAnte->setElProx(nullptr);
        pUltimo = pAnte;
    }

    else{
        pAnte->setElProx(pAtual->getElProx());
    }

    tamanhoLista--;
    delete pAtual;
}

template <class TL>
void Lista<TL>::percorrer() {
    Elemento<TL>* pAux = pPrimeiro;

    while (pAux != nullptr) {
        pAux = pAux->getElProx();
    }
}

}
}




#endif

