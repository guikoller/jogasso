#include "Espadachim.h"

void Espadachim::iniciaVariaveis(){
    this->estaPulando = false;
    this->espelhado = false;
    STATE = parado;
}


void Espadachim::iniciaTextura(){
    if (!this->textura.loadFromFile("Textures/Jogador/1/spritesheet.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Espadachim::iniciaSprite(){
    this->sprite.setTexture(this->textura);
     
    this->frameAtual = sf::IntRect(0, 0, 96, 96);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(2.f,2.f);

    this->hitBox.setSize(sf::Vector2f(35,45));
    this->hitBox.setOutlineThickness(2.f);
    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setFillColor(sf::Color::Transparent);
}

Espadachim::Espadachim(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    this->iniciaFisica();
}
Espadachim::~Espadachim(){}

void Espadachim::upadateMovimento(){
    this->velocidade.x = 0.f;
    this->velocidade.y = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->velocidade.x += -7.f;
        //Esquuerda
        STATE = andando_esquerda;
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->velocidade.x += 7.f;
        //Direita
        this->STATE= andando_direita;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) /*&& !estaPulando*/)
    {
        this->estaPulando = true;
        this->velocidade.y += -11.f;
        //Cima
        this->STATE = pulando;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        // this->estaPulando = true;
        this->velocidade.y += 7.f;
        //Cima
        this->STATE = pulando;
    }  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        this->STATE = atacando;
    }
    this->move(velocidade.x,velocidade.y);
    this->sprite.setPosition(sf::Vector2f(this->hitBox.getPosition().x-80,this->hitBox.getPosition().y-92));
}

void Espadachim::uptadeAnimacao(){
    if (this->STATE == parado)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.3f)
        {  
            this->frameAtual.top = 384.f;
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
            this->frameAtual.top = 0;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);  
        }
        this->sprite.setScale(2.f,2.f);
        this->sprite.setOrigin(0.f,0.f);
        this->espelhado = false;
    }
    else if (this->STATE == andando_esquerda)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.07f)
        {
            this->frameAtual.top = 0;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        this->espelhado = true;
        this->sprite.setScale(-2.f,2.f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
    }
    else if (this->STATE == atacando)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.01f)
        {
            this->frameAtual.top = 192.f;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 96.f)
                this->frameAtual.left = 0;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        
        if (this->espelhado)
        {
            this->sprite.setScale(-2.f,2.f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
        }else{
           this->sprite.setScale(2.f,2.f);
            this->sprite.setOrigin(0.f,0.f); 
        }
        
        
    }

    else if (this->STATE == pulando)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.01f)
        {
            this->frameAtual.top = 576.f;
            this->frameAtual.left = 0.f;    
            
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        
        if (this->espelhado)
        {
            this->sprite.setScale(-2.f,2.f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
        }else{
           this->sprite.setScale(2.f,2.f);
            this->sprite.setOrigin(0.f,0.f); 
        } 
        
    }
    
    this->STATE = parado;
    
}