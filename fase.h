#ifndef _FASE_H_
#define _FASE_H_
#include "stdafx.h"
#include "ente.h"
#include "listaEntidades.h"
#include "gerenciador_colisoes.h"

namespace TrabalhoJogo {
namespace Fases{

class Fase : public Ente{
protected:
    Listas::ListaEntidades lista_ents;
    Gerenciadores::Gerenciador_colisoes GC;
    
    const int MaxEsqueletos;
    int pontos;
    int totalInimigos;
    float pontuacao;
    float tempoTotal;
    
    std::vector<Entidades::Entidade*> entidades;

    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;

    void criarEsqueletos();
    void criarPlataformas();
    void criarCenario();
    void adicionarEntidade(Entidades::Entidade* pE);
    
    virtual void criarInimigos() = 0;
    virtual void criarObstaculos() = 0;

    
public:
    //construtora e destrutora
    Fase();
    virtual ~Fase();
    
    void setJogadores(Entidades::Personagens::Jogador* jog1,Entidades::Personagens::Jogador* jog2);
    void setTempo(float dt);
    void desenharEntidades();
    void operator++();
    void calcularPontos(float tempoTotal);
    float getPontos();

    
    virtual void executar() = 0;

};

}
}

#endif
