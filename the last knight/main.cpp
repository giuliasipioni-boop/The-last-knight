#include "gerenciador_grafico.h"
#include "jogador.h"

int main()
{
    Gerenciador_grafico grafico;

    Ente::setGG(&grafico);

    Jogador jogador1(1, 100, 200, 1);

    while (grafico.jogoAberto())
    {
        grafico.processarEventos();

        jogador1.executar();

        grafico.limparTela();

        jogador1.desenhar();

        grafico.mostrarJogo();
    }

    return 0;
}