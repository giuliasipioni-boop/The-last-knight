#ifndef _MENU_H_
#define _MENU_H_

#include "ente.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace TheLastKnights {

class Menu : public Ente {
private:
    int nJog;
    int faseSelecionada;
    int acao;
    bool jogoPausado;

    sf::Font fonteMenu;
    std::vector<sf::Text> textos;

public:
    Menu();
    virtual ~Menu();

    virtual void executar();

    bool carregarMenu();
    void posicionarTextos();

    bool cliqueEmOpcao(sf::RenderWindow& janela,sf::Text& texto);

    int getNJog() const;
    int getFaseSelecionada() const;
    int getAcao() const;

    void setJogoPausado(bool pausado);

    void mostrarRanking();
    void mostrarPontuacao(float pontos);
    bool salvarRanking(std::string nome, float pontos);
};

}

#endif
