#include "State.h"

State::State(sf::RenderWindow *window){
    this->window  =  window;
}

State::~State()
{
}

void State::update(){
    this->updateEntidade();
    this->updateColisao();
}