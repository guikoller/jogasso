#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>


#include "Jogador.h"

class Jogo{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimilazão
    
    Jogador *jogador;

    void initJogador();
    void initWindow();
public:
    Jogo(/* args */);
    ~Jogo();
    
    //Functions
    void update();
    void renderJogador();
    void render();
    void updateJogador();
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
};


