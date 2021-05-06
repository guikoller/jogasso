#pragma once
#include "State.h"
class GameState : public State{
private:
    /* data */
public:
    GameState(sf::RenderWindow *window);
    ~GameState();

    void endState();
    void update();
    void render();
};

