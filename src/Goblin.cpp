#include "Goblin.h"


void Goblin::iniciaVariaveis(){
}


void Goblin::iniciaTextura(){
    if (!this->textura.loadFromFile("Textures/Inimigos/Goblin.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Goblin::iniciaSprite(){
    this->sprite.setTexture(this->textura);
     
    this->frameAtual = sf::IntRect(0, 0, 64, 64);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(8.f,8.f);

    this->hitBox.setSize(sf::Vector2f(400,170));
    this->hitBox.setOutlineThickness(2.f);
    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setFillColor(sf::Color::Transparent);
}




Goblin::Goblin(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    STATE = parado;
}

Goblin::~Goblin(){}

void Goblin::upadateMovimento(){
    
    
    this->sprite.setPosition(sf::Vector2f(this->hitBox.getPosition().x,this->hitBox.getPosition().y));
}

void Goblin::uptadeAnimacao(){
if (this->STATE == parado)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.3f)
        {  
            this->frameAtual.top = 192.f;
            this->frameAtual.left += 64.f;            
            if(this->frameAtual.left >= 640.f)
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
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);  
        }
        this->sprite.setScale(8.f,8.f);
        this->sprite.setOrigin(0.f,0.f);
        this->espelhado = false;
    }
    else if (this->STATE == andando_esquerda)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 0;
            this->frameAtual.left += 64.f;
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        this->espelhado = true;
        this->sprite.setScale(-8.f,8.f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 8.f, 0.f);
    }
    else if (this->STATE == atacando)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.01f)
        {
            this->frameAtual.top = 0.f;
            this->frameAtual.left += 64.f;
            if(this->frameAtual.left >= 64.f)
                this->frameAtual.left = 0;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        
        if (this->espelhado)
        {
            this->sprite.setScale(-8.f,8.f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 8.f, 0.f);
        }else{
           this->sprite.setScale(8.f,8.f);
            this->sprite.setOrigin(0.f,0.f); 
        }        
    }
    
    this->STATE = parado;
       
}


void Goblin::jogadorPerto(Jogador *jogador, sf::Clock tempo){
    if (this->hitBox.getGlobalBounds().intersects(jogador->getGlobalBounds()))
    {
        this->STATE = atacando;
    }    
}