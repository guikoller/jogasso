#include "Jogador.h"

void Jogador::initTexture(){
    if (!this->texture.loadFromFile("Textures/player.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Jogador::initSprite(){
    this->sprite.setTexture(this->texture);
}

Jogador::Jogador(){
    this->initTexture();
    this->initSprite();
}

Jogador::~Jogador(){

}

void Jogador::upadateMovimento(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->sprite.move(-1.f,0.f);//Esquuerda
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->sprite.move(1.f,0.f);//Direita
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->sprite.move(0.f,-1.f);//Cima
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->sprite.move(0.f,1.f);//Baixo
    }
    
}


void Jogador::update(){
    this->upadateMovimento();
}

void Jogador::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}