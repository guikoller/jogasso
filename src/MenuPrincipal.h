#pragma once

#include "LevelPrincipal.h"

class MenuPrincipal : public State{
private:    
    sf::RectangleShape background;
    
public:
    MenuPrincipal(sf::RenderWindow *window);
    virtual ~MenuPrincipal();
    

    virtual void render(sf::RenderTarget &target);
};

