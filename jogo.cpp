#include "jogo.h"
#include "ente.h"

namespace TheLastKnights {

Jogo::Jogo(): GG(),GE(nullptr),pJog1(nullptr),pJog2(nullptr),pFaseAtual(nullptr),faseAtual(1),menu(),nJog(1) {
    Ente::setGG(&GG);
}

Jogo::~Jogo() {
    delete GE;
    delete pFaseAtual;

    delete pJog1;
    delete pJog2;

    Ente::setGG(nullptr);
}

void Jogo::executar() {

    // Loop principal
    while (GG.jogoAberto()) {

        menu.setJogoPausado(false);
        menu.executar();

        if (!GG.jogoAberto()) {
            break;
        }
        
        // Recebe as escolhas do menu
        nJog = menu.getNJog();
        faseAtual = menu.getFaseSelecionada();

        // Cria os jogadores
        pJog1 = new Entidades::Personagens::Jogador(50.0, 300.0, 1);
        if (nJog == 2) {
            pJog2 = new Entidades::Personagens::Jogador(150.0, 300.0, 2);
        }
        // Cria o gerenciador de eventos
        GE = new Gerenciadores::Gerenciador_eventos(&GG.getJanela(), pJog1, pJog2);

        // Cria a fase escolhida
        if (faseAtual == 1) {
            pFaseAtual = new Fases::Masmorra();
        }
        else {
            pFaseAtual = new Fases::Castelo();
        }

        pFaseAtual->setJogadores(pJog1, pJog2);

        float tempoTotal = 0.0;
        float pontosTotal = 0.0;

        relogio.restart();

        // Loop da partida
        while (GG.jogoAberto()) {

            float dt = relogio.restart().asSeconds();
            GE->executar();
            tempoTotal += dt;
            
            if (!GG.jogoAberto()) {
                break;
            }

            // Pausar partida
            if (GE->estaPausado()) {
                dt = 0.0;
                continue;
            }

            // Atualiza o tempo
            pJog1->setTempo(dt);
            if (pJog2 != nullptr) {
                pJog2->setTempo(dt);
            }
            pFaseAtual->setTempo(dt);

            // Executa os jogadores
            pJog1->executar();

            if (pJog2 != nullptr) {
                pJog2->executar();
            }

            // Executa a fase
            pFaseAtual->executar();

            // DERROTA
            if (pJog1->morto() && (pJog2 == nullptr || pJog2->morto())) {
        
                break;
            }

            // VITORIA
            if (pFaseAtual->vitoria()) {
                pFaseAtual->calcularPontos(tempoTotal);
                pontosTotal += pFaseAtual->getPontos();
                // Venceu a Masmorra
                if (faseAtual == 1) {
                    delete pFaseAtual;
                    pFaseAtual = new Fases::Castelo();
                    pFaseAtual->setJogadores(pJog1, pJog2);
                    faseAtual = 2;
                    tempoTotal = 0.0;
                    relogio.restart();

                    continue;
                }
                // Venceu o Castelo
                else if (faseAtual == 2) {
                    menu.mostrarPontuacao(pontosTotal);
                    break;
                }
            }

            // Desenha o jogo
            GG.iniciarImagJogo();
            pFaseAtual->desenharEntidades();
            if (pJog1 != nullptr && !pJog1->morto()) {
                pJog1->desenhar();
            }
            if (pJog2 != nullptr && !pJog2->morto()) {
                pJog2->desenhar();
            }
            GG.mostrarJogo();
        }
    }
}

}
