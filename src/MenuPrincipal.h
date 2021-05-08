#pragma once

#include "LevelPrincipal.h"
#include "Botao.h"

class MenuPrincipal : public State{
private:    
    sf::RectangleShape background;
    
    Botao *btn;

public:
    MenuPrincipal(sf::RenderWindow *window);
    virtual ~MenuPrincipal();
    
    void update();
    virtual void render(sf::RenderTarget &target);
};

