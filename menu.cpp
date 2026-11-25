#include "menu.h"
#include "gerenciador_grafico.h"

namespace TrabalhoJogo {

Menu::Menu() : Ente(), opcaoSelecionada(0), jogoIniciado(false) {
}

Menu::~Menu() {
}

void Menu::executar() {
    jogoIniciado = mostrar();
}

bool Menu::iniciouJogo() const {
    return jogoIniciado;
}

bool Menu::mostrar() {
    if (pGG == 0) return false;

    sf::RenderWindow& janela = pGG->getJanela();
    sf::Font fonte;
    if (!fonte.loadFromFile("imagens/DejaVuSans.ttf")) {
        std::cerr << "Nao foi possivel carregar imagens/DejaVuSans.ttf" << std::endl;
        return false;
    }

    sf::Text titulo("THE LAST KNIGHT", fonte, 56);
    titulo.setStyle(sf::Text::Bold);
    titulo.setFillColor(sf::Color(235, 220, 185));
    titulo.setPosition(640.f - titulo.getLocalBounds().width / 2.f, 190.f);

    sf::Text subtitulo("Uma aventura medieval", fonte, 22);
    subtitulo.setFillColor(sf::Color(210, 210, 210));
    subtitulo.setPosition(640.f - subtitulo.getLocalBounds().width / 2.f, 270.f);

    sf::Text iniciar("INICIAR JOGO", fonte, 30);
    sf::Text sair("SAIR", fonte, 30);
    iniciar.setPosition(550.f, 390.f);
    sair.setPosition(590.f, 455.f);

    sf::Text ajuda("Use as setas para escolher e ENTER para confirmar", fonte, 16);
    ajuda.setFillColor(sf::Color(205, 205, 205));
    ajuda.setPosition(640.f - ajuda.getLocalBounds().width / 2.f, 590.f);

    sf::RectangleShape painel(sf::Vector2f(620.f, 330.f));
    painel.setPosition(330.f, 170.f);
    painel.setFillColor(sf::Color(12, 15, 25, 205));
    painel.setOutlineThickness(2.f);
    painel.setOutlineColor(sf::Color(190, 155, 90));

    while (janela.isOpen()) {
        sf::Event evento;
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                janela.close();
                return false;
            }

            if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::Up ||
                    evento.key.code == sf::Keyboard::Down) {
                    opcaoSelecionada = 1 - opcaoSelecionada;
                }
                else if (evento.key.code == sf::Keyboard::Return) {
                    return opcaoSelecionada == 0;
                }
                else if (evento.key.code == sf::Keyboard::Escape) {
                    return false;
                }
            }
        }

        iniciar.setFillColor(opcaoSelecionada == 0
            ? sf::Color(255, 210, 105) : sf::Color::White);
        sair.setFillColor(opcaoSelecionada == 1
            ? sf::Color(255, 210, 105) : sf::Color::White);

        pGG->limparTela();
        pGG->desenharFundo();
        janela.draw(painel);
        janela.draw(titulo);
        janela.draw(subtitulo);
        janela.draw(iniciar);
        janela.draw(sair);
        janela.draw(ajuda);
        pGG->mostrarJogo();
    }

    return false;
}

}
