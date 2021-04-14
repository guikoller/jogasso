#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>


#include "Entidades/Entidade.h"

class Jogo{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimilazão
    
    Entidade *jogador;

    void initEntidade();
    void initWindow();
public:
    Jogo(/* args */);
    ~Jogo();
    
    //Functions
    void update();
    void updateColisao();
    void renderEntidade();
    void render();
    void updateEntidade();
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
    void rodar();
};


