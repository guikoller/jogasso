#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Entidade.h"
#include "Personagem.h"
#include "Espadachim.h"

#include "Monstro.h"
#include "levelPrincipal.h"


class Jogo{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimilazão
    
    sf::Clock dtClock;
    float dt;

    levelPrincipal *level;

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
    void render();
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
    void rodar();
};


