#include "fase.h"
#include "chao.h"
#include "esqueleto.h"
#include "plataforma.h"
#include "personagem.h"
#include "inimigo.h"
#include "stdafx.h"

namespace TheLastKnights {
namespace Fases {

Fase::Fase(): lista_ents(),GC(),MaxEsqueletos(7),pJog1(nullptr),pJog2(nullptr),pontos(-1), totalInimigos(-1), pontuacao(-1.0),tempoTotal(0.0){
    GC.setLimites(1280.0, 620.0);
}

Fase::~Fase() {
    for (size_t i = 0; i < lista_ents.getTamanho(); i++) {
        delete lista_ents[i];
    }

    lista_ents.limpar();
}


void Fase::adicionarEntidade(Entidades::Entidade* pE) {
    if (pE != nullptr) {
        lista_ents.incluir(pE);
    }
}

void Fase::setJogadores(Entidades::Personagens::Jogador* jog1,Entidades::Personagens::Jogador* jog2) {
    pJog1 = jog1;
    pJog2 = jog2;

    GC.setJog1(jog1);
    GC.setJog2(jog2);

    for (size_t i = 0; i < lista_ents.getTamanho(); i++) {

        Entidades::Personagens::Inimigo* pI = dynamic_cast<Entidades::Personagens::Inimigo*>(lista_ents[i]);

        if (pI != nullptr) {
            pI->setJogadores(jog1, jog2);
        }
    }
}


void Fase::setTempo(float dt) {
        GC.setTempo(dt);

        for (size_t i = 0; i < lista_ents.getTamanho(); i++) {

            Entidades::Entidade* pE = lista_ents[i];

            if (pE != nullptr) {
                pE->setTempo(dt);
            }
        }
}



void Fase::desenharEntidades() {

    for (size_t i = 0; i < lista_ents.getTamanho(); i++) {

        Entidades::Entidade* pE =lista_ents[static_cast<int>(i)];

        if (pE != nullptr) {

            Entidades::Personagens::Personagem* pP = dynamic_cast<Entidades::Personagens::Personagem*>(pE);

            if (pP == nullptr || !pP->morto()) {
                pE->desenhar();
            }
        }
    }
}
// Cria os esqueletos comuns as fases
void Fase::criarEsqueletos() {

    int quantidade = 3 + rand() % (MaxEsqueletos - 2);

    // Posicoes possiveis dos esqueletos
    const float posicoes[7][2] = {

        {350.0, 500.0},
        {450.0, 180.0},  // Plataforma 2
        {900.0, 500.0},
        {650.0, 80.0},   // Plataforma 3
        {1100.0, 500.0},
        {550.0, 500.0},
        {780.0, 500.0}

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

    int quantidade =3 + rand() % 5;

    const float posicoes[7][2] = {

        {200.0, 465.0},  // Plataforma 1
        {420.0, 335.0},  // Plataforma 2
        {630.0, 205.0},  // Plataforma 3
        {840.0, 320.0},  // Plataforma 4
        {1050.0, 440.0}, // Plataforma 5
        {950.0, 180.0},  // Plataforma 6
        {330.0, 120.0}   // Plataforma 7

    };

    for (int i = 0; i < quantidade; i++) {

        float x = posicoes[i][0];
        float y = posicoes[i][1];
        
        Entidades::Obstaculos::Plataforma* pA = new Entidades::Obstaculos::Plataforma(posicoes[i][0], posicoes[i][1]);
            
            pA->setEscala(0.40);
            adicionarEntidade(pA);
            GC.incluirObstaculo(pA);
    }
        
}

// Organiza a criacao do cenario
void Fase::criarCenario() {

    Entidades::Chao* pC =
        new Entidades::Chao(0.0, 620.0, 1280.0, 100.0);

    adicionarEntidade(pC);
    GC.incluirChao(pC);
    
}

void Fase::operator++(){
    pontos++;
}

void Fase::calcularPontos(float tempoTotal){
    
    pontos = 0;
    totalInimigos = 0;
    pontuacao = 0;
    
    
    for (size_t i = 0; i < lista_ents.getTamanho(); i++) {

            Entidades::Personagens::Inimigo* pI = dynamic_cast<Entidades::Personagens::Inimigo*>(lista_ents[i]);

            if (pI != nullptr) {
                totalInimigos++;

                if (pI->morto()) {
                    operator++();
                }
            }
        }


        pontuacao = (pontos * 1000.0) /(totalInimigos * tempoTotal);

        if (pJog2 != nullptr) {
            pontuacao /= 2;
        }
    }

float Fase::getPontos(){
    return pontuacao;
}

bool Fase::vitoria(){
    for (size_t i = 0; i < lista_ents.getTamanho(); i++) {

        Entidades::Personagens::Inimigo* pI = dynamic_cast<Entidades::Personagens::Inimigo*>(lista_ents[i]);

        if (pI != nullptr && !pI->morto()) {
            return false;
        }
    }

    return true;
}
    
    
}
}


