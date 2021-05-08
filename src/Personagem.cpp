#include "Personagem.h"
Personagem::~Personagem(){}
Personagem::Personagem(){}


void Personagem::iniciaAnimacao(){
    this->timerAnimacao.restart();
}
const sf::FloatRect Personagem::getGlobalBounds() const{
    return this->hitBox.getGlobalBounds();
}
const sf::Vector2f Personagem::getPosicao() const{
    return this->hitBox.getPosition();
}
sf::Sprite Personagem::getSprite(){
    return this->sprite;
}

void Personagem::setPosicao(const float x, const float y){
    this->hitBox.setPosition(x, y);
}
void Personagem::resetVelY(){
    this->velocidade.y = 0.f;
}
void Personagem::resetVelX(){
    this->velocidade.x = 0.f;
}


void Personagem::move(const float x, const float y){   
    this->hitBox.move(x,y);
}

void Personagem::update(){
    this->upadateMovimento();
    this->uptadeAnimacao();
}

void Personagem::render(sf::RenderTarget&target){
    target.draw(this->sprite);
    target.draw(this->hitBox);
}