#include "Jogador.h"

void Jogador::initTexture(){
    if (!this->texture.loadFromFile("Textures/Jogador/1/spritesheetv1.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Jogador::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(3.f,3.f);

    this->frameAtual = sf::IntRect(0, 0, 64, 64);
    this->sprite.setTextureRect(this->frameAtual);

}

Jogador::Jogador(){
    this->initTexture();
    this->initSprite();
}

Jogador::~Jogador(){

}

void Jogador::upadateMovimento(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->sprite.move(-2.f,0.f);//Esquuerda
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->sprite.move(2.f,0.f);//Direita
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->sprite.move(0.f,-2.f);//Cima
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->sprite.move(0.f,2.f);//Baixo
    }
    
}


void Jogador::update(){
    this->upadateMovimento();
}

void Jogador::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}