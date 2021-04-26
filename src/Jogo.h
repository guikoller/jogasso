#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>


#include "Jogador.h"
#include "Monstro.h"
#include "TileMap.h"

class Jogo{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimilazão
    
    sf::Clock dtClock;
    float dt;

    TileMap *mapa;

    Jogador *jogador;
    Monstro *monstro;

    void initEntidade();
    void initWindow();
public:
    Jogo(/* args */);
    ~Jogo();
    
    //Functions
    void update();
    void updateDT();
    void updateSFMLevents();
    void updateColisao();
    void renderEntidade();
    void render();
    void updateEntidade();
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
    void rodar();
};


