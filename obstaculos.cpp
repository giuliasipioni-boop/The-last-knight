#include "Obstaculos.h"

Obstaculos::Obstaculos(float x, float y, bool danoso)
    : Entidade(x, y), danoso(danoso) {
}

Obstaculos::~Obstaculos() {
}

bool Obstaculos::ehDanoso() const {
    return danoso;
}
