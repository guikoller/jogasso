#include "State.h"

State::State(sf::RenderWindow *window){
    this->window  =  window;
    this->quit = false;
}

State::~State()
{
}

void State::update(){
    // this->updateEntidade();
    // this->updateColisao();
    this->updateKeybinds();
}

void State::checkQuit(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }    
}

const bool &State::getQuit() const{
    return this->quit;
}

void State::updateKeybinds(){
    return this->checkQuit();
}


void State::endState(){
    printf("STATE FINALIZADO!\n");
}