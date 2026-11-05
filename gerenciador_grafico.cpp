#include "gerenciador_grafico.h"
#include "ente.h"


Gerenciador_grafico::Gerenciador_grafico():janelaJogo(sf::VideoMode(1280, 720), "The Last Knight"), movimentoXJog1(0), movimentoXJog2(0){

   janelaJogo.setFramerateLimit(120);

   carregarImagens();
   configurarFundo();

}

Gerenciador_grafico::~Gerenciador_grafico(){

}

void Gerenciador_grafico::desenharFigura(const sf::Drawable& figura){

    janelaJogo.draw(figura);

}

void Gerenciador_grafico::desenharEnte(Ente* pE){

    if(pE != nullptr){
        desenharFigura(pE->getFigura());
    }
}

void Gerenciador_grafico::limparTela(){

    janelaJogo.clear();
}

void Gerenciador_grafico::mostrarJogo(){

    janelaJogo.display();
}

bool Gerenciador_grafico::jogoAberto()const {

    return janelaJogo.isOpen();
}

void Gerenciador_grafico::processarEventos()
{
    sf::Event evento;

    while (janelaJogo.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
            janelaJogo.close();

        if (evento.type == sf::Event::KeyPressed)
        {
            if (evento.key.code == sf::Keyboard::A)
                movimentoXJog1 -= 10;

            if (evento.key.code == sf::Keyboard::D)
                movimentoXJog1 += 10;

            if (evento.key.code == sf::Keyboard::Left)
                movimentoXJog2 -= 10;

            if (evento.key.code == sf::Keyboard::Right)
                movimentoXJog2 += 10;
        }
    }
}

 void Gerenciador_grafico::carregarImagens(){

    carregarTextura("fundo", "imagens/fundo.png");
    carregarTextura("jogador1", "imagens/jogador1.png");

    /*carregarTextura(
        "jogador2",   
    );*/

    carregarTextura("esqueleto", "imagens/esqueleto.png");

    carregarTextura("mago", "imagens/mago.png");

    carregarTextura("rei", "imagens/rei.png");

    carregarTextura("plataforma", "imagens/plataforma.png");

    carregarTextura("garras", "imagens/garras.png");

    carregarTextura("fogueira", "imagens/fogueira.png");

    carregarTextura("baril", "imagens/baril.png");

 }


bool Gerenciador_grafico::carregarTextura(const std::string& nome, const std::string& pasta){
    if (texturas.find(nome) != texturas.end()){
        return true;
    }

    sf::Texture& textura = texturas[nome];

    if (!textura.loadFromFile(pasta)){
        std::cerr << "Erro ao carregar: " << pasta << std::endl;

        texturas.erase(nome);
        return false;
    }

    return true;

}

bool Gerenciador_grafico::aplicarTextura(Ente* pE, const std::string& nome){
    if (pE == nullptr){
        return false;
    }

    auto it = texturas.find(nome);

    if (it == texturas.end()){
        std::cerr << "Textura nao encontrada: " << nome << std::endl;

        return false;
    }

    pE->setTextura(it->second);

    return true;

}

void Gerenciador_grafico::configurarFundo(){
    auto it = texturas.find("fundo");

    if (it == texturas.end()){
        return;
    }
    
    fundo.setTexture(it->second);

    fundo.setPosition(0.f, 0.f);

    sf::Vector2u tamanho = it->second.getSize();

    if (tamanho.x > 0 && tamanho.y > 0){
        fundo.setScale(
            1280.f / tamanho.x,
            720.f / tamanho.y
        );
    }
}

void Gerenciador_grafico::desenharFundo(){
    if (fundo.getTexture() != nullptr){
        desenharFigura(fundo);
    }
}


void Gerenciador_grafico::iniciarImagJogo(){
    limparTela();
    desenharFundo();
}


int Gerenciador_grafico::getMovimentoXJog1()
{
    int movimento = movimentoXJog1;
    movimentoXJog1 = 0;
    return movimento;
}

int Gerenciador_grafico::getMovimentoXJog2(){
    int movimento = movimentoXJog2;
    movimentoXJog2 = 0;
    return movimento;
}
