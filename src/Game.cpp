#include "Game.h"


void Game::initWindow(){
    this->window.create(sf::VideoMode(width,height),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game(/* args */){
    this->initWindow();
}

Game::~Game(){
}


void Game::update(){
    //pega todos o eventos da janela
    while (this->window.pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)//se a janela for fechada
            this->window.close();
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
            this->window.close();// checa se uma tecla foi precionada e se foi, se é esc                   
    }
    
}

void Game::render(){

}


const sf::RenderWindow& Game::getWindow() const{
    return this->window; 
}