#include "Tile.h"

Tile::Tile(sf::Texture& texture, sf::IntRect texture_rect,float x, float y, bool dan, bool s){
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(texture_rect);
    this->sprite.setScale(2.f,2.f);
    this->pos = sf::Vector2f(x,y);
    this->sprite.setPosition(pos);
    this->dano = dan;
    this->solido = s;
    this->hitBox.setSize(sf::Vector2f(64,64));
    this->hitBox.setFillColor(sf::Color::Transparent);
    this->hitBox.setPosition(pos);
}
Tile::~Tile(){

}

const sf::FloatRect Tile::getGlobalBounds()const{
    return this->sprite.getGlobalBounds();
}

void Tile::update(){

}
