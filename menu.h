#ifndef _MENU_H_
#define _MENU_H_

#include "ente.h"

namespace TrabalhoJogo {

class Menu : public Ente {
private:
    int opcaoSelecionada;
    bool jogoIniciado;

public:
    Menu();
    virtual ~Menu();

    virtual void executar();
    bool mostrar();
    bool iniciouJogo() const;
};

}

#endif
