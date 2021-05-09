#include "Monstro.h"


void Monstro::iniciaVariaveis(){
}


void Monstro::iniciaTextura(){
    if (!this->textura.loadFromFile("Textures/Inimigos/Monstro.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Monstro::iniciaSprite(){
    this->sprite.setTexture(this->textura);
     
    this->frameAtual = sf::IntRect(0, 0, 64, 64);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(3.f,3.f);

    this->hitBox.setSize(sf::Vector2f(40,40));
    this->hitBox.setOutlineThickness(2.f);
    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setFillColor(sf::Color::Transparent);
}




Monstro::Monstro(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    STATE = parado;
}

Monstro::~Monstro(){}

void Monstro::upadateMovimento(){
    
    if(this->hitBox.getPosition().y <= 280)
    {
        if(this->hitBox.getPosition().x >= 1475)
            setVelX(-2.5);
        if(this->hitBox.getPosition().x <= 400)
            setVelX(2.5f);
    }
    else if(this->hitBox.getPosition().y == 595)
    {
        if(this->hitBox.getPosition().x >= 1220)
            setVelX(-2.5f);
        if(this->hitBox.getPosition().x <= 70)
            setVelX(2.5f);
    }
    else
    {
        if(this->hitBox.getPosition().x >= 1475)
            setVelX(-2.5f);
        if(this->hitBox.getPosition().x <= 70)
            setVelX(2.5f);
    }
    if(this->velocidade.x > 0)
        STATE = andando_direita;
    if(this->velocidade.x < 0)
        STATE = andando_esquerda;
    this->move(velocidade.x, velocidade.y);
    this->sprite.setPosition(sf::Vector2f(this->hitBox.getPosition().x-75,this->hitBox.getPosition().y-82));
}

void Monstro::uptadeAnimacao(){
    if (this->STATE == parado)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.3f)
        {  
            this->frameAtual.top = 0.f;
            this->frameAtual.left += 64.f;            
            if(this->frameAtual.left >= 192.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
    }else if (this->STATE == andando_direita)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 0;
            this->frameAtual.left += 64.f;
            if(this->frameAtual.left >= 320.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
    }
    else if (this->STATE == andando_esquerda)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 0;
            this->frameAtual.left += 64.f;
            if(this->frameAtual.left >= 320.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
    }
    STATE = parado;    
}