#include "masmorra.h"
#include "mago.h"
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
        {200.f, 400.f},
        {400.f, 400.f},
        {600.f, 400.f},
        {800.f, 400.f},
        {1000.f, 400.f},
        {1100.f, 300.f}
    };

    for (int i = 0; i < quantidade; i++) {

        Entidades::Personagens::Mago* pM = new Entidades::Personagens::Mago(posicoes[i][0],posicoes[i][1]);
        
        pM->setEscala(0.65f);
        pM->virar(false);
        pM->setJogadores(pJog1, pJog2);

        adicionarEntidade(pM);
        GC.incluirInimigo(pM);
    }
}

void Masmorra::criarObstaculos() {
    
    criarPlataformas();
    criarBaril();
}


void Masmorra::criarBaril() {

    int quantidade = 3 + rand() % 3;

    const float posicoes[5][2] = {
        {250.f, 550.f},   // Barril 1
        {600.f, 550.f},   // Barril 2
        {950.f, 550.f},   // Barril 3
        {400.f, 550.f},   // Barril 4
        {800.f, 550.f}    // Barril 5
    };

    for (int i = 0; i < quantidade; i++) {

        float x = posicoes[i][0];
        float y = posicoes[i][1];

        // Criar Barril em (x, y)
        // Adicionar a lista_ents
        // Registrar no GC

        (void)x;
        (void)y;
    }
}

void Masmorra::executar() {

    lista_ents.executar();

    GC.executar();
}

}
}
