#include "Portal.h"

void Portal::iniciaSprite(){
    if (!this->textura.loadFromFile("Textures/Obstaculos/Portal.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}

    this->sprite.setTexture(this->textura);
    this->sprite.setTextureRect(sf::IntRect(0,0,64,64));
    this->sprite.setScale(2.f,2.f);
}


Portal::Portal(){
    this->iniciaSprite();
}

Portal::~Portal(){
}

void Portal::update(){}

void Portal::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}
