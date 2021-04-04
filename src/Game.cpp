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
    printf("LOL\n");
}

void Game::render(){

}


const sf::RenderWindow& Game::getWindow() const{
    return this->window; 
}