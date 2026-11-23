#include "castelo.h"
#include "rei.h"
#include "stdafx.h"

namespace TrabalhoJogo {
namespace Fases {

Castelo::Castelo(): Fase(),MaxReis(4){
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
        {200.0, 400.0},
        {400.0, 400.0},
        {600.0, 400.0},
        {800.0, 400.0},
        {1000.0, 400.0},
        {1100.0, 300.0}
    };

    for (int i = 0; i < quantidade; i++) {

        Entidades::Personagens::Rei* pR = new Entidades::Personagens::Rei(posicoes[i][0],posicoes[i][1]);
        
        pR->setEscala(0.65);
        pR->virar(false);
        pR->setJogadores(pJog1, pJog2);

        adicionarEntidade(pR);
        GC.incluirInimigo(pR);
    }
}

void Castelo::criarObstaculos() {
    
    criarPlataformas();
    criarFogueiras();
}


void Castelo::criarFogueiras() {

    int quantidade = 3 + rand() % 3;

    const float posicoes[5][2] = {
        {250.0, 550.0},   // Fogueira 1
        {600.0, 550.0},   // Fogueira 2
        {950.0, 550.0},   // Fogueira 3
        {400.0, 550.0},   // Fogueira 4
        {800.0, 550.0}    // Fogueira 5
    };

    for (int i = 0; i < quantidade; i++) {

        float x = posicoes[i][0];
        float y = posicoes[i][1];

        // Criar Fogueira em (x, y)
        // Adicionar a lista_ents
        // Registrar no GC

        (void)x;
        (void)y;
    }
}

void Castelo::executar() {

    lista_ents.executar();

    GC.executar();
}

