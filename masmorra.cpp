#include "masmorra.h"
#include "mago.h"
#include "barril.h"
#include "stdafx.h"

namespace TheLastKnights {
namespace Fases {

Masmorra::Masmorra(): Fase(),MaxMagos(6) {
    criarCenario();
    criarInimigos();
    criarObstaculos();
}


Masmorra::~Masmorra() {
}

void Masmorra::criarInimigos() {
    criarEsqueletos();
    criarMagos();
}

void Masmorra::criarMagos() {
    
    int quantidade = 3 + rand() % (MaxMagos - 2);
    
    const float posicoes[6][2] = {

        {620.0, 450.0},
        {690.0, 30.0},   // Plataforma 3
        {1180.0, 450.0},
        {490.0, 80.0},   // Plataforma 2
        {850.0, 450.0},
        {380.0, 450.0}

    };
    
    for (int i = 0; i < quantidade; i++) {
        
        Entidades::Personagens::Mago* pM = new Entidades::Personagens::Mago(posicoes[i][0],posicoes[i][1]);
        
        pM->setEscala(0.55);
        pM->virar(false);
        pM->setJogadores(pJog1, pJog2);
        
        adicionarEntidade(pM);
        GC.incluirInimigo(pM);
    }
}

void Masmorra::criarObstaculos() {
    
    criarPlataformas();
    criarBarril();
}


void Masmorra::criarBarril() {
    
    int quantidade = 3 + rand() % 3;
    
    const float posicoes[5][2] = {

        {430.0, 550.0},   // Barril 1
        {750.0, 550.0},   // Barril 2
        {1110.0, 550.0},  // Barril 3
        {600.0, 550.0},   // Barril 4
        {930.0, 550.0}    // Barril 5

    };
    
    for (int i = 0; i < quantidade; i++) {
        
            Entidades::Obstaculos::Barril* pB = new Entidades::Obstaculos::Barril(posicoes[i][0], posicoes[i][1]);
            
            pB->setEscala(0.25);
            adicionarEntidade(pB);
            GC.incluirObstaculo(pB);
            
    }
}

void Masmorra::executar(){
            
    lista_ents.executar();
    GC.executar();
}
    
}
}
