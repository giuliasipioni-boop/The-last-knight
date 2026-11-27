#ifndef GERENCIADOR_EVENTOS_H
#define GERENCIADOR_EVENTOS_H

#include "stdafx.h"

namespace TheLastKnights {
namespace Entidades {
namespace Personagens {
    class Jogador;
}
}
}

namespace TheLastKnights {
namespace Gerenciadores {

class Gerenciador_eventos {
private:
    sf::RenderWindow* pJanela;

    Entidades::Personagens::Jogador* pJogador1;
    Entidades::Personagens::Jogador* pJogador2;
    
    bool pausado;

public:
    //construtora e destrutora
    Gerenciador_eventos(sf::RenderWindow* janela, Entidades::Personagens::Jogador* jog1 = 0, Entidades::Personagens::Jogador* jog2 = 0);
    ~Gerenciador_eventos();

    void executar();
    void verificarTeclasPressionada(sf::Keyboard::Key tecla);
    void verificarTeclaSolta(sf::Keyboard::Key tecla);
    bool estaPausado() const;
};

}
}

#endif
