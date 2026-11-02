#ifndef _GERENCIADOR_GRAFICO_H_
#define _GERENCIADOR_GRAFICO_H_
#include "stdafx.h"
#include "ente.h"

class Ente;

class Gerenciador_grafico {
private:
    sf::RenderWindow janelaJogo;

public:
//construtora e destrutora
    Gerenciador_grafico ();
    ~Gerenciador_grafico();

//outras funcoes
    void desenharFigura(const sf::Drawable& figura);
    void desenharEnte(Ente *pE);
    void limparTela();
    void mostrarJogo();  
    bool jogoAberto() const;
    void processarEventos();
    bool teclaPressionada(sf::Keyboard::Key tecla) const;
};


#endif
