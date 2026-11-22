#include "fase.h"
#include "esqueleto.h"
#include "personagem.h"
#include "inimigo.h"
#include "stdafx.h"

namespace TrabalhoJogo {
namespace Fases {

Fase::Fase(): lista_ents(),GC(),MaxEsqueletos(6),pJog1(nullptr),pJog2(nullptr) {
    GC.setLimites(1280.f, 620.f);
}

Fase::~Fase() {
    lista_ents.limpar();

    for (size_t i = 0; i < entidades.size(); i++) {
        delete entidades[i];
    }

    entidades.clear();
}

void Fase::adicionarEntidade(Entidades::Entidade* pE) {
    if (pE != nullptr) {
        entidades.push_back(pE);
        lista_ents.incluir(pE);
    }
}

void Fase::setJogadores(Entidades::Personagens::Jogador* jog1,Entidades::Personagens::Jogador* jog2) {
    pJog1 = jog1;
    pJog2 = jog2;

    GC.setJog1(jog1);
    GC.setJog2(jog2);

    for (size_t i = 0; i < entidades.size(); i++) {

        Entidades::Personagens::Inimigo* pI =dynamic_cast<Entidades::Personagens::Inimigo*>(entidades[i]);

        if (pI != nullptr) {
            pI->setJogadores(jog1, jog2);
        }
    }
}

void Fase::setTempo(float dt) {

    GC.setTempo(dt);

    for (size_t i = 0; i < entidades.size(); i++) {

        Entidades::Personagens::Personagem* pP =dynamic_cast<Entidades::Personagens::Personagem*>(entidades[i]);

        if (pP != nullptr) {
            pP->setTempo(dt);
        }
    }
}

void Fase::desenharEntidades() {

    for (size_t i = 0; i < lista_ents.getTamanho(); i++) {

        Entidades::Entidade* pE =lista_ents[static_cast<int>(i)];

        if (pE != nullptr) {
            pE->desenhar();
        }
    }
}

// Cria os esqueletos comuns as fases
void Fase::criarEsqueletos() {

    int quantidade = 3 + rand() % (MaxEsqueletos - 2);

    // Posicoes possiveis dos esqueletos
    const float posicoes[6][2] = {
        {100.0, 500.0},
        {300.0, 500.0},
        {500.0, 500.0},
        {700.0, 500.0},
        {900.0, 500.0},
        {1100.0, 500.0}
    };

    for (int i = 0; i < quantidade; i++) {

        Entidades::Personagens::Esqueleto* pE =new Entidades::Personagens::Esqueleto(posicoes[i][0],posicoes[i][1]);
        
        pE->setEscala(0.8);
        pE->virar(false);
       
        adicionarEntidade(pE);
        GC.incluirInimigo(pE);
    }
    

}

void Fase::criarPlataformas() {

    int quantidade = 3 + rand() % 3;

    const float posicoes[5][2] = {
        {200.0, 500.0},  // Plataforma 1
        {500.0, 400.0},  // Plataforma 2
        {800.0, 500.0},  // Plataforma 3
        {350.0, 300.0},  // Plataforma 4
        {950.0, 300.0}   // Plataforma 5
    };

    for (int i = 0; i < quantidade; i++) {

        float x = posicoes[i][0];
        float y = posicoes[i][1];

        // Criar Plataforma em (x, y)
        // Adicionar a lista_ents
        // Registrar no GC
    }
}

// Organiza a criacao do cenario
void Fase::criarCenario() {

    criarPlataformas();
}

}
}


