#include "plataforma.h"
#include "gerenciador_grafico.h"

namespace TheLastKnights {
namespace Entidades {
namespace Obstaculos {

Plataforma::Plataforma(float x, float y):Obstaculo(x, y, false), empuxo(gravidade) {

    if (pGG != nullptr) {
            pGG->aplicarTextura(this, "plataforma");
        }
}

Plataforma::~Plataforma() {
}

void Plataforma::executar() {
    velY += (gravidade - empuxo) * tempo;
    aplicarFisica();
    
    if (x == 630 && !danoso && rand() % 10000 == 1) {

        danoso = true;
        pGG->aplicarTextura(this, "garras");
        setEscala(0.15);
    }
}

void Plataforma::salvar() {
}

void Plataforma::aplicarFisica() {
    x += velX * tempo;
    y += velY * tempo;

    figura.setPosition(x, y);
}

void Plataforma::obstaculizar(Personagens::Personagem* pP){

    if (pP != nullptr) {

        pP->setVelocidade(0.0, pP->getVelocidadeY());

        if (ehDanoso()) {
            pP->Dano();
        }
    }
}

}
}
}
