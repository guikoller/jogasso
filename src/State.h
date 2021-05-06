#pragma once

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Entidade.h"
#include "Personagem.h"
#include "Espadachim.h"

#include "LevelBase.h"
#include "LevelPrincipal.h"

#include "MenuPrincipal.h"

class State{
private:
    sf::RenderWindow *window;
public:
    State(sf::RenderWindow *window);
    ~State();
    
    virtual void endState() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderTarget &target) = 0;
};


