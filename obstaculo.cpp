#include "obstaculo.h"
namespace TrabalhoJogo{
namespace Entidades{
namespace Obstaculos{

Obstaculo::Obstaculo(float x, float y, bool danoso): Entidade(x, y), danoso(danoso) {
}

Obstaculo::~Obstaculo() {
}

bool Obstaculo::ehDanoso() const {
    return danoso;
}

}
}
}
