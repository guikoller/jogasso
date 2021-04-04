#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>


#include "Player.h"

class Game{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimilazão
    
    Player *player;

    void initPlayer();
    void initWindow();
public:
    Game(/* args */);
    ~Game();
    
    //Functions
    void update();
    void renderPlayer();
    void render();
    void updatePlayer();
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
};


