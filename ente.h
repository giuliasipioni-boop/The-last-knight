#ifndef _ENTE_H_
#define _ENTE_H_
#include "stdafx.h"

class Gerenciador_grafico;

class Ente{
protected:
    int id;
    
    static int proxID;
    static Gerenciador_grafico* pGG;
    sf::Sprite figura;

public:
    Ente();
    virtual ~Ente();
    virtual void executar()=0;
    void desenhar();
    static void setGG(Gerenciador_grafico* pG);
    void setTextura(const sf::Texture& textura);
    const sf::Drawable& getFigura() const;
    int getID();
    
};


#endif
