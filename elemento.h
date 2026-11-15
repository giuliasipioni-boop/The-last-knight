#ifndef ELEMENTO_H
#define ELEMENTO_H

namespace TrabalhoJogo {
namespace Listas {

template<class TE>
class Elemento {
private:
    Elemento<TE>* pProx;
    TE* pInfo;

public:
    Elemento(TE* pE)
        : pProx(0), pInfo(pE) {
    }

    ~Elemento() {
    }

    void setProx(Elemento<TE>* pE) {
        pProx = pE;
    }

    Elemento<TE>* getProx() const {
        return pProx;
    }

    TE* getInfo() const {
        return pInfo;
    }
};

}
}

#endif

