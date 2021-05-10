#include "Goblin.h"


void Goblin::iniciaVariaveis(){
    this->vida = 1000;
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

    this->hitBox.setSize(sf::Vector2f(120,150));
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
    
    /*if(this->hitBox.getPosition().x < 400)
    {
        setVelX(6.f);
        STATE = andando_direita;
    }
    if(this->hitBox.getPosition().x > 1100)
    {
        setVelX(-6.f);
        STATE = andando_esquerda;
    }
    if(this->velocidade.x > 0)
        STATE = andando_direita;
    else if(this->velocidade.x < 0)
        STATE = andando_esquerda;
    this->move(velocidade.x, velocidade.y);*/
    this->sprite.setPosition(sf::Vector2f(this->hitBox.getPosition().x - 200,this->hitBox.getPosition().y - 200));
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
    }else if (this->STATE == andando_esquerda)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 320.f;
            this->frameAtual.left += 64.f;
            if(this->frameAtual.left >= 320.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);  
        }
        this->sprite.setScale(8.f,8.f);
        this->sprite.setOrigin(0.f,0.f);
        this->espelhado = false;
    }
    else if (this->STATE == andando_direita)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 320.f;
            this->frameAtual.left += 64.f;
            if(this->frameAtual.left >= 320.f)
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


void Goblin::jogadorPerto(Jogador *jogador, float *dt){

    
    if (this->hitBox.getGlobalBounds().intersects(jogador->getGlobalBounds()))
    {
        if(jogador->hitBox.getPosition().x > this->hitBox.getPosition().x)
            espelhado = true;
        else if (jogador->hitBox.getPosition().x <= this->hitBox.getPosition().x)
            espelhado = false;
        if(*dt > 4.0)
        {
            this->STATE = atacando;
            printf("goblin atacou\n");
            // jogador perde vida
            *dt = 0;
        }
    }    
}