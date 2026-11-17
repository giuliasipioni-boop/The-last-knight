#ifndef _GERENCIADOR_GRAFICO_H_
#define _GERENCIADOR_GRAFICO_H_
#include "stdafx.h"
#include "ente.h"

namespace TrabalhoJogo {
class Ente;
}

namespace TrabalhoJogo {
namespace Gerenciadores{

class Gerenciador_grafico {
private:
    sf::RenderWindow janelaJogo;
    
    std::map<std::string, sf::Texture> texturas;
    sf::Sprite fundo;
    
    
public:
    //construtora e destrutora
    Gerenciador_grafico ();
    ~Gerenciador_grafico();
    
    //outras funcoes
    void desenharFigura(const sf::Drawable& figura);
    void desenharEnte(TrabalhoJogo::Ente *pE);
    void limparTela();
    void mostrarJogo();
    bool jogoAberto() const;
    void carregarImagens();
    bool carregarTextura(const std::string& nome, const std::string& caminho);
    bool aplicarTextura(TrabalhoJogo::Ente* pE, const std::string& nome);
    void configurarFundo();
    void desenharFundo();
    void iniciarImagJogo();
    sf::RenderWindow& getJanela();
    
};

}
}

#endif
