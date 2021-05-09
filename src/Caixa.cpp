#include "Caixa.h"

void Caixa::iniciaSprite(){
    if (!this->textura.loadFromFile("Textures/Obstaculos/Caixa.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}

    this->sprite.setTexture(this->textura);
    this->sprite.setScale(3.f,3.f);
}


Caixa::Caixa(){
    this->iniciaSprite();
}

Caixa::~Caixa(){
}

void Caixa::update(){
}

void Caixa::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}
