#include "State.h"

State::State(sf::RenderWindow *window){
    this->window  =  window;
    this->quit = false;
    iniciaFontes();
}

State::~State()
{
}


void State::iniciaFontes(){
    if(!this->fonte.loadFromFile("Font/font.ttf")){
        throw("ERRO FONTE NÃO CARREGADA");
    } 
}

void State::update(){
    // this->updateEntidade();
    // this->updateColisao();
    this->updateKeybinds();
    this->updateMousePosition();
    std::cout<<this->mousePosWindow.x <<", "<< this->mousePosWindow.y << std::endl;
    system("clear");
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

void State::updateMousePosition(){
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}