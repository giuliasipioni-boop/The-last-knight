#ifndef _BARRIL_H_
#define _BARRIL_H_

#include "obstaculo.h"
#include "personagem.h"

namespace TheLastKnights {
namespace Entidades {

namespace Personagens{
class Jogador;
}

namespace Obstaculos {

class Barril : public Obstaculo {
private:
    float tamanho;
    
public:
    Barril(float x, float y);
    virtual ~Barril();

    void executar();
    void salvar();

    void obstaculizar(Personagens::Personagem* pP);
};

}
}
}

#endif
