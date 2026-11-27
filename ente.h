#ifndef _ENTE_H_
#define _ENTE_H_
#include "stdafx.h"

namespace TheLastKnights{
namespace Gerenciadores {
class Gerenciador_grafico;
}
}


namespace TheLastKnights {

class Ente{
protected:
    int id;
    static int proxID;
    
    static Gerenciadores::Gerenciador_grafico* pGG;
    sf::Sprite figura;
    
public:
    //construtora e destrutora
    Ente();
    virtual ~Ente();
    
    virtual void executar()=0;
    void desenhar();
    static void setGG(Gerenciadores::Gerenciador_grafico* pG);
    void setTextura(const sf::Texture& textura);
    const sf::Drawable& getFigura() const;
    int getID();
    void setEscala(float escala);
    void virar(bool direita);
    
};

}

#endif
