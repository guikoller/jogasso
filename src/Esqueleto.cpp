#include "Esqueleto.h"


void Esqueleto::iniciaVariaveis(){
}


void Esqueleto::iniciaTextura(){
    if (!this->textura.loadFromFile("Textures/Inimigos/Esqueleto.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Esqueleto::iniciaSprite(){
    this->sprite.setTexture(this->textura);
     
    this->frameAtual = sf::IntRect(0, 0, 96, 96);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(3.f,3.f);

    this->hitBox.setSize(sf::Vector2f(40,40));
    this->hitBox.setOutlineThickness(2.f);
    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setFillColor(sf::Color::Transparent);
}




Esqueleto::Esqueleto(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    STATE = parado;
}

Esqueleto::~Esqueleto(){}

void Esqueleto::upadateMovimento(){
    
    if(this->hitBox.getPosition().y <= 280)
    {
        if(this->hitBox.getPosition().x >= 1475)
            setVelX(-3.5);
        if(this->hitBox.getPosition().x <= 400)
            setVelX(3.5f);
    }
    else if(this->hitBox.getPosition().y == 595)
    {
        if(this->hitBox.getPosition().x >= 1220)
            setVelX(-3.5f);
        if(this->hitBox.getPosition().x <= 70)
            setVelX(3.5f);
    }
    else
    {
        if(this->hitBox.getPosition().x >= 1475)
            setVelX(-3.5f);
        if(this->hitBox.getPosition().x <= 70)
            setVelX(3.5f);
    }
    if(this->velocidade.x > 0)
        STATE = andando_direita;
    if(this->velocidade.x < 0)
        STATE = andando_esquerda;
    this->move(velocidade.x, velocidade.y);
    this->sprite.setPosition(sf::Vector2f(this->hitBox.getPosition().x+155,this->hitBox.getPosition().y-150));
}

void Esqueleto::uptadeAnimacao(){
    if (this->STATE == parado)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.3f)
        {  
            this->frameAtual.top = 0.f;
            this->frameAtual.left += 96.f;            
            if(this->frameAtual.left >= 288.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
    }else if (this->STATE == andando_direita)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 192.f;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);  
        }
        this->sprite.setScale(-3.f,3.f);
        this->sprite.setOrigin(0.f,0.f);
        this->espelhado = false;
    }
    else if (this->STATE == andando_esquerda)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 192.f;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        this->espelhado = true;
        this->sprite.setScale(3.f,3.f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
    }
    else if (this->STATE == atacando)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.01f)
        {
            this->frameAtual.top = 96.f;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 96.f)
                this->frameAtual.left = 0;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        
        if (this->espelhado)
        {
            this->sprite.setScale(-3.f,3.f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
        }else{
           this->sprite.setScale(3.f,3.f);
            this->sprite.setOrigin(0.f,0.f); 
        }
        
        
    }
    
    this->STATE = parado;   
}