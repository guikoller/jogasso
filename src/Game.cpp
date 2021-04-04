#include "Game.h"


void Game::initWindow(){
    this->window.create(sf::VideoMode(1280,720),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initPlayer(){
    this->player  = new Player();
}


Game::Game(){
    this->initWindow();
    this->initPlayer();
}

Game::~Game(){
    delete this->player;
}


void Game::update(){
    //pega todos o eventos da janela
    while (this->window.pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)//se a janela for fechada
            this->window.close();
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
            this->window.close();// checa se uma tecla foi precionada e se foi, se é esc                   
    }
    
    this->updatePlayer();

}

void Game::render(){
    this->window.clear();
    //renderizão do jogo vai aqui


    //
    this->window.display();
}


void Game::updatePlayer(){
    this->player->update();
}

const sf::RenderWindow& Game::getWindow() const{
    return this->window; 
}