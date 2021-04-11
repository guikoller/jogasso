#include "Tile.h"

Tile::Tile(sf::Texture& texture, sf::IntRect texture_rect, bool dano):dano(dano){
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(texture_rect);
}
Tile::~Tile(){

}

const sf::FloatRect Tile::getGlobalBounds()const{
    return this->sprite.getGlobalBounds();
}

void Tile::update(){

}

void Tile::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}