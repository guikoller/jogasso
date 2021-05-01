#include "Martelador.h"

void Martelador::iniciaVariaveis(){
    this->espelhado = false;
    STATE = parado;
}


void Martelador::iniciaTextura(){
    if (!this->textura.loadFromFile("Textures/Jogador/1/spritesheet.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Martelador::iniciaSprite(){
    this->sprite.setTexture(this->textura);
     
    this->frameAtual = sf::IntRect(0, 0, 96, 96);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(2.f,2.f);
}


Martelador::Martelador(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    this->iniciaFisica();
}