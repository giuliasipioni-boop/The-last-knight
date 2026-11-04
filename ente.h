#ifndef _ENTE_H_
#define _ENTE_H_
#include "stdafx.h"

class Gerenciador_grafico;

class Ente{
protected:
    int id;
    static Gerenciador_grafico* pGG;
    //Figura* pFig;  
    sf::Sprite figura;

public:
    Ente(int id);
    virtual ~Ente();
    virtual void executar()=0;
    void desenhar();
    static void setGG(Gerenciador_grafico* pG);
    void setTextura(const sf::Texture& textura);
    const sf::Drawable& getFigura() const;
    
};


#endif
