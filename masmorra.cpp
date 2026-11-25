#include "masmorra.h"
#include "mago.h"
#include "barril.h"
#include "stdafx.h"

namespace TrabalhoJogo {
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
        {500.0, 400.0},
        {700.0, 400.0},
        {1100.0, 400.0},
        {500.0, 300.0},
        {700.0, 300.0},
        {1100.0, 300.0}
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
        {300.f, 550.f},   // Barril 1
        {600.f, 550.f},   // Barril 2
        {950.f, 550.f},   // Barril 3
        {400.f, 550.f},   // Barril 4
        {800.f, 550.f}    // Barril 5
    };
    
    for (int i = 0; i < quantidade; i++) {
        
        float x = posicoes[i][0];
        float y = posicoes[i][1];
        
        for (int i = 0; i < quantidade; i++) {
            
            Entidades::Obstaculos::Barril* pB = new Entidades::Obstaculos::Barril(posicoes[i][0], posicoes[i][1]);
            
            pB->setEscala(0.25);
            adicionarEntidade(pB);
            GC.incluirObstaculo(pB);
            
        }
    }
}

void Masmorra::executar(){
            
    lista_ents.executar();
    GC.executar();
}
    
}
}
