#include "Obstaculos.h"
namespace TrabalhoJogo{
namespace Entidades{
namespace Obstaculos{

Obstaculos::Obstaculos(float x, float y, bool danoso)
: Entidade(x, y), danoso(danoso) {
}

Obstaculos::~Obstaculos() {
}

bool Obstaculos::ehDanoso() const {
    return danoso;
}

}
}
}
