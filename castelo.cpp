#include "castelo.h"
#include "rei.h"
#include "projetil.h"
#include "fogueira.h"
#include "stdafx.h"

namespace TheLastKnights {
namespace Fases {

Castelo::Castelo(): Fase(),MaxReis(5){
    criarCenario();
    criarInimigos();
    criarObstaculos();
}


Castelo::~Castelo() {
}

void Castelo::criarInimigos() {
    criarEsqueletos();
    criarReis();
}

void Castelo::criarReis() {
    
    int quantidade = 3 + rand() % (MaxReis - 2);
    
    const float posicoes[6][2] = {

        {620.0, 450.0},
        {690.0, 30.0},   // Plataforma 3
        {1180.0, 450.0},
        {490.0, 80.0},   // Plataforma 2
        {850.0, 450.0},
        {380.0, 450.0}

    };
    
    for (int i = 0; i < quantidade; i++) {
        
        Entidades::Personagens::Rei* pR = new Entidades::Personagens::Rei(posicoes[i][0],posicoes[i][1]);
        
        pR->setEscala(0.4);
        pR->virar(false);
        pR->setJogadores(pJog1, pJog2);
        
        adicionarEntidade(pR);
        GC.incluirInimigo(pR);
    }
}

void Castelo::criarProjeteis() {

    const int tamanho = lista_ents.getTamanho();

    for (int i = 0; i < tamanho; i++) {

        Entidades::Personagens::Rei* pR = dynamic_cast<Entidades::Personagens::Rei*>(lista_ents[i]);

        if (pR != nullptr) {

            Entidades::Projetil* pProj = pR->getProjetil();

            if (pProj != nullptr && !pProj->estaAssociado()) {

                pProj->setEscala(0.04);

                adicionarEntidade(pProj);
                GC.incluirProjetil(pProj);

                pProj->setAsssociado(true);
            }
        }
    }
}


void Castelo::criarObstaculos() {
    
    criarPlataformas();
    criarFogueiras();
}


void Castelo::criarFogueiras() {
    
    int quantidade = 3 + rand() % 3;
    
    const float posicoes[5][2] = {

        {450.0, 550.0},   // Fogueira 1
        {730.0, 550.0},   // Fogueira 2
        {1000.0, 550.0},  // Fogueira 3
        {580.0, 550.0},   // Fogueira 4
        {1150.0, 550.0}   // Fogueira 5

    };
    
    for (int i = 0; i < quantidade; i++) {
        
            Entidades::Obstaculos::Fogueira* pF = new Entidades::Obstaculos::Fogueira(posicoes[i][0], posicoes[i][1]);
            
            pF->setEscala(0.25);
            adicionarEntidade(pF);
            GC.incluirObstaculo(pF);
        
    }
}



void Castelo::executar() {
    
    lista_ents.executar();
    criarProjeteis();
    GC.executar();
}

}
}
