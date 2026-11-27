#include "menu.h"
#include "gerenciador_grafico.h"
#include "stdafx.h"

#define FONTE "imagens/fonte.ttf"

namespace TheLastKnights {

Menu::Menu():Ente(),nJog(1),faseSelecionada(1),acao(0),jogoPausado(false) {
}

Menu::~Menu() {
}

// Carrega o menu
bool Menu::carregarMenu() {
    if (!pGG->aplicarTextura(this, "menu")) {
        return false;
    }

    if (!fonteMenu.loadFromFile(FONTE)) {
        return false;
    }
    posicionarTextos();

    return true;
}

// Posiciona as opcoes do menu
void Menu::posicionarTextos() {
    textos.clear();

    const std::string opcoes[6] = {
        "1 jogador",
        "2 jogadores",
        "Masmorra",
        "Castelo",
        "Continuar",
        "Ranking"
    };

    const float posicoes[6][2] = {
        {150.0, 300.0},
        {440.0, 300.0},
        {150.0, 500.0},
        {440.0, 500.0},
        {950.0, 300.0},
        {950.0, 450.0}
    };

    for (int i = 0; i < 6; i++) {

        sf::Text texto(opcoes[i], fonteMenu, 35);
        sf::FloatRect limites = texto.getLocalBounds();

        texto.setOrigin(limites.left + limites.width / 2.0,limites.top + limites.height / 2.0);
        texto.setPosition(posicoes[i][0],posicoes[i][1]);
        textos.push_back(texto);
    }
}

// Verifica a posicao do mouse
bool Menu::cliqueEmOpcao(sf::RenderWindow& janela,sf::Text& texto) {

    sf::Vector2f mouse = janela.mapPixelToCoords(sf::Mouse::getPosition(janela));
    
    return texto.getGlobalBounds().contains(mouse);
}

// Executa o menu principal
void Menu::executar() {

    acao = 0;
    if (pGG == nullptr) {
        return;
    }

    if (!carregarMenu()) {
        pGG->getJanela().close();
        return;
    }

    sf::RenderWindow& janela = pGG->getJanela();
    sf::Text titulo("The Last Knight", fonteMenu, 75);
    titulo.setPosition(330.0, 70.0);
    sf::Text jogadores("Jogadores", fonteMenu, 55);
    jogadores.setPosition(190.0, 200.0);
    sf::Text fases("Fases", fonteMenu, 55);
    fases.setPosition(245.0, 400.0);

    while (janela.isOpen()) {
        sf::Event evento;
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                janela.close();
                return;
            }
            // Inicia uma nova partida
            if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::Enter) {
                    acao = 1;
                    return;
                }
                // Continua a partida pausada
                if (evento.key.code == sf::Keyboard::Escape && jogoPausado) {
                    acao = 2;
                    return;
                }
            }

            // Verifica cliques
            if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
                for (int i = 0; i < 6; i++) {
                    if (cliqueEmOpcao(janela, textos[i])) {
                        switch (i) {
                            case 0:
                                nJog = 1;
                                break;
                            case 1:
                                nJog = 2;
                                break;
                            case 2:
                                faseSelecionada = 1;
                                break;
                            case 3:
                                faseSelecionada = 2;
                                break;
                            case 4:
                                if (jogoPausado) {
                                    acao = 2;
                                    return;
                                }
                                break;
                            case 5:
                                mostrarRanking();
                                break;
                        }
                        
                        break;
                    }
                }
            }
        }

        if (!janela.isOpen()) {
            return;
        }

        // Configura as cores
        for (int i = 0; i < 6; i++) {
            textos[i].setFillColor(sf::Color::White);
        }

        textos[nJog - 1].setFillColor(sf::Color::Yellow);

        textos[faseSelecionada + 1].setFillColor(
            sf::Color::Yellow
        );

        if (!jogoPausado) {
            textos[4].setFillColor(sf::Color(130, 130, 130));
        }

        // Desenha o menu
        pGG->limparTela();
        pGG->desenharEnte(this);
        pGG->desenharFigura(titulo);
        pGG->desenharFigura(jogadores);
        pGG->desenharFigura(fases);

        for (int i = 0; i < 6; i++) {
            pGG->desenharFigura(textos[i]);
        }

        pGG->mostrarJogo();
    }
}

int Menu::getNJog() const {
    return nJog;
}

int Menu::getFaseSelecionada() const {
    return faseSelecionada;
}

int Menu::getAcao() const {
    return acao;
}

void Menu::setJogoPausado(bool pausado) {
    jogoPausado = pausado;
}

// Salva a pontuacao no arquivo
bool Menu::salvarRanking(std::string nome, float pontos) {

    std::ofstream arquivo("ranking.txt", std::ios::app);
    arquivo << pontos << " " << nome << std::endl;

    arquivo.close();

    return !arquivo.fail();
}

// Mostra o ranking
void Menu::mostrarRanking() {
    sf::RenderWindow& janela = pGG->getJanela();
    std::ifstream arquivo("ranking.txt");
    std::vector<std::pair<float, std::string>> ranking;

    float pontos;
    std::string nome;

    while (arquivo >> pontos) {

        std::getline(arquivo, nome);

        if (!nome.empty() && nome[0] == ' ') {
            nome.erase(0, 1);
        }

        ranking.push_back(std::make_pair(pontos, nome));
    }

    arquivo.close();

    // Ordena as pontuacoes
    std::sort(ranking.rbegin(), ranking.rend());

    sf::Text titulo("Ranking", fonteMenu, 60);
    titulo.setPosition(520.0, 60.0);

    sf::Text voltar("Voltar", fonteMenu, 35);
    voltar.setPosition(570.0, 620.0);

    while (janela.isOpen()) {

        sf::Event evento;

        while (janela.pollEvent(evento)) {

            if (evento.type == sf::Event::Closed) {
                janela.close();
                return;
            }

            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) {
                return;
            }

            if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {

                if (cliqueEmOpcao(janela, voltar)) {
                    return;
                }
            }
        }

        pGG->limparTela();
        pGG->desenharEnte(this);
        pGG->desenharFigura(titulo);
        pGG->desenharFigura(voltar);

        // Mostra os cinco melhores
        for (size_t i = 0; i < ranking.size() && i < 5; i++) {

            std::ostringstream linha;

            linha << i + 1 << ". "
                  << ranking[i].second << " - "
                  << std::fixed << std::setprecision(2)
                  << ranking[i].first;

            sf::Text texto(linha.str(), fonteMenu, 35);

            texto.setPosition(350.0, 180.0 + i * 75.0);

            pGG->desenharFigura(texto);
        }

        pGG->mostrarJogo();
    }
}

// Tela final da partida
void Menu::mostrarPontuacao(float pontos) {

    if (pGG == nullptr) {
        return;
    }

    sf::RenderWindow& janela = pGG->getJanela();

    std::string nome;

    sf::Text titulo("Pontuacao", fonteMenu, 55);
    titulo.setPosition(480.0, 150.0);

    std::ostringstream valor;

    valor << std::fixed << std::setprecision(2) << pontos;

    sf::Text pontuacao(valor.str(), fonteMenu, 55);
    pontuacao.setPosition(540.0, 250.0);

    // Caixa para inserir o nome
    sf::RectangleShape caixa(sf::Vector2f(500.0, 60.0));

    caixa.setPosition(390.0, 380.0);
    caixa.setFillColor(sf::Color(40, 30, 50));
    caixa.setOutlineThickness(2.0);
    caixa.setOutlineColor(sf::Color::White);

    sf::Text textoNome("", fonteMenu, 32);
    textoNome.setPosition(405.0, 390.0);

    while (janela.isOpen()) {

        sf::Event evento;

        while (janela.pollEvent(evento)) {

            if (evento.type == sf::Event::Closed) {
                janela.close();
                return;
            }

            // Digita o nome
            if (evento.type == sf::Event::TextEntered) {

                if (evento.text.unicode == 8) {

                    if (!nome.empty()) {
                        nome.erase(nome.size() - 1);
                    }
                }

                else if (evento.text.unicode >= 32 && evento.text.unicode < 127 && nome.size() < 18) {
                    nome += static_cast<char>(
                        evento.text.unicode
                    );
                }
            }

            // Salva ao apertar Enter
            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {

                if (nome.find_first_not_of(' ') !=
                    std::string::npos) {

                    if (salvarRanking(nome, pontos)) {
                        return;
                    }

                    std::cerr << "Erro ao salvar ranking"
                              << std::endl;
                }
            }
        }

        textoNome.setString(nome);

        pGG->limparTela();

        pGG->desenharEnte(this);
        pGG->desenharFigura(titulo);
        pGG->desenharFigura(pontuacao);
        pGG->desenharFigura(caixa);
        pGG->desenharFigura(textoNome);

        pGG->mostrarJogo();
    }
}

}
