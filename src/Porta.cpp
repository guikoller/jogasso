#include "Porta.h"

void Porta::iniciaSprite(){
    if (!this->textura.loadFromFile("Textures/Obstaculos/Porta/Iddle.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}

    this->sprite.setTexture(this->textura);
    this->sprite.setScale(2.f,2.f);
}


Porta::Porta(){
    this->iniciaSprite();
}

Porta::~Porta(){
}

void Porta::update(){}

void Porta::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}
