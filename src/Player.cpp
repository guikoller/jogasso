#include "Player.h"

void Player::initTexture(){
    this->texture.loadFromFile("Textures");
}
void Player::initSprite(){

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