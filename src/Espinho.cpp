#include "Espinho.h"

void Espinho::iniciaSprite(){
    if (!this->textura.loadFromFile("Textures/Obstaculos/Espinho.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}

    this->sprite.setTexture(this->textura);
    this->sprite.setScale(4.f,4.f);
}


Espinho::Espinho(){
    this->iniciaSprite();
}

Espinho::~Espinho(){
}

void Espinho::update(){
}

void Espinho::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}
