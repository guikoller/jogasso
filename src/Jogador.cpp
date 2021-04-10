#include "Jogador.h"


void Jogador::iniciaVariaveis(){
    this->estadoAnimacao = ESTADOS_ANIMACOES::PARADO;
}


void Jogador::iniciaTextura(){
    if (!this->texture.loadFromFile("Textures/Jogador/1/spritesheet.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Jogador::iniciaSprite(){
    this->sprite.setTexture(this->texture);
     
    this->frameAtual = sf::IntRect(0, 0, 96, 96);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(3.f,3.f);

}

void Jogador::iniciaAnimacao(){
    this->timerAnimacao.restart();
}


Jogador::Jogador(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
}

Jogador::~Jogador(){

}

void Jogador::upadateMovimento(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->sprite.move(-2.f,0.f);//Esquuerda
        this->estadoAnimacao = MOVE_ESQUERDA;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->sprite.move(2.f,0.f);//Direita
        this->estadoAnimacao = MOVE_DIREITA;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->sprite.move(0.f,-2.f);//Cima
        this->estadoAnimacao = PULANDO;
    }// }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
    //     this->sprite.move(0.f,2.f);//Baixo
    // }
    
}

void Jogador::uptadeAnimacao(){
    if (this->estadoAnimacao == ESTADOS_ANIMACOES::PARADO)
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
    }else if (this->estadoAnimacao == ESTADOS_ANIMACOES::MOVE_DIREITA)
    {
        if (this->timerAnimacao.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->frameAtual.top = 0;
            this->frameAtual.left += 96.f;
            if(this->frameAtual.left >= 480.f)
                this->frameAtual.left = 0;    
            this->timerAnimacao.restart();
            this->sprite.setTextureRect(this->frameAtual);
        }
        
    }
    
    this->estadoAnimacao = ESTADOS_ANIMACOES::PARADO;
      
    
}


void Jogador::update(){
    this->upadateMovimento();
    this->uptadeAnimacao();
}

void Jogador::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}