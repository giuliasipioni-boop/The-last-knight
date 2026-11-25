#include "fase.h"
#include "esqueleto.h"
#include "plataforma.h"
#include "personagem.h"
#include "inimigo.h"
#include "stdafx.h"

namespace TrabalhoJogo {
namespace Fases {

Fase::Fase(): lista_ents(),GC(),MaxEsqueletos(7),pJog1(nullptr),pJog2(nullptr),pontos(-1), totalInimigos(-1), pontuacao(-1.0){
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
    const float posicoes[6][2] = {
        {500.0, 500.0},
        {700.0, 500.0},
        {1100.0, 500.0},
        {500.0, 350.0},
        {700.0, 350.0},
        {1100.0, 350.0}
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
        {500.0, 370.0},  // Plataforma 1
        {680.0, 430.0},  // Plataforma 2
        {280.0, 430.0},  // Plataforma 3
        {300.0, 300.0},  // Plataforma 4
        {950.0, 410.0},  // Plataforma 5
        {800.0, 360.0},  // Plataforma 6
        {700.0, 250.0}   // Plataforma 7
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

    criarPlataformas();
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


        float pontuacao = (pontos * 1000.0) /(totalInimigos * tempoTotal);

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


