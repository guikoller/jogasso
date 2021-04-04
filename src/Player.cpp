#include "Player.h"

void Player::initTexture(){
    if(!this->texture.loadFromFile("Textures/quadrado.png")){
        std::cout<<"ERRO::PLAYER:: NÃO CONSEGUIU CARREGAR PLAYER SHEET"<<"\n";
    }
}
void Player::initSprite(){
    this->sprite.setTexture(this->texture);
}

Player::Player(){
    this->initTexture();
    this->initSprite();
}

Player::~Player(){}

void Player::update(){

}

void Player::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}