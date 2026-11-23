#include "jogo.h"
#include "ente.h"

namespace TrabalhoJogo {

Jogo::Jogo(): GG(),GE(nullptr),pJog1(nullptr),pJog2(nullptr),pMasmorra(nullptr) {
    
    Ente::setGG(&GG);

    // Criacao dos jogadores
    pJog1 = new Entidades::Personagens::Jogador(100.0, 300.0, 1);
    pJog2 = new Entidades::Personagens::Jogador(200.0, 350.0, 2);
    /*if (quantidadeJogadores == 2) {
        pJog2 = new Entidades::Personagens::Jogador(200.0, 450.0, 2);
    }*/
    
    // Gerenciador de eventos
    GE = new Gerenciadores::Gerenciador_eventos(&GG.getJanela(),pJog1,pJog2);

    // Primeira fase
    pMasmorra = new Fases::Masmorra();

    pMasmorra->setJogadores(pJog1, pJog2);
}

Jogo::~Jogo() {

    delete GE;
    delete pMasmorra;

    delete pJog1;
    delete pJog2;

    Ente::setGG(nullptr);
}

void Jogo::executar() {

    while (GG.jogoAberto()) {

        float dt = relogio.restart().asSeconds();

        if (dt > 0.05f) {
            dt = 0.05f;
        }

        GE->executar();

        if (!GG.jogoAberto()) {
            break;
        }

        pJog1->setTempo(dt);
        pJog2->setTempo(dt);

        pMasmorra->setTempo(dt);

        pJog1->executar();

        if (pJog2 != nullptr) {
            pJog2->executar();
        }

        pMasmorra->executar();
        
        
        // GAME OVER
        // Quando os dois jogadores morrerem
        if (pJog1->morto() &&(pJog2 == nullptr || pJog2->morto())) {

            //voltar ao menu quando tiver o menu pronto
            
            break;
        }

        GG.iniciarImagJogo();

        pMasmorra->desenharEntidades();
        
        
        if (pJog1 != nullptr && !pJog1->morto()){
            pJog1->desenhar();
        }

        if (pJog2 != nullptr && !pJog2->morto()) {
            pJog2->desenhar();
        }
        GG.mostrarJogo();
    }
}
}
