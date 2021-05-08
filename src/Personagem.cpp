#include "Personagem.h"
Personagem::~Personagem(){}
Personagem::Personagem(){}




void Personagem::iniciaFisica(){
    this->gravidade = 9.f;
    this->VelMaxY = 15.f;
}
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

void Personagem::updateFisica(){
    this->velocidade.y += 1.0 * this->gravidade;
    if(std::abs(this->velocidade.y) >  this->VelMaxY){
        this->velocidade.y = this->VelMaxY *((this->velocidade.y < 0.f) ? -1.f : 1.f);
    }
	this->move(this->velocidade.x, velocidade.y);
}


void Personagem::move(const float x, const float y){   
    this->hitBox.move(x,y);
}

void Personagem::update(){
    this->updateFisica();
    this->upadateMovimento();
    this->uptadeAnimacao();
}

void Personagem::render(sf::RenderTarget&target){
    target.draw(this->sprite);
    //target.draw(this->hitBox);
}