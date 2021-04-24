#include "Monstro.h"


void Monstro::iniciaVariaveis(){
}


void Monstro::iniciaTextura(){
    if (!this->texture.loadFromFile("Textures/Inimigos/Monstro/Idle (64x64).png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Monstro::iniciaSprite(){
    this->sprite.setTexture(this->texture);
     
    this->frameAtual = sf::IntRect(0, 0, 64, 64);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(3.f,3.f);

}

void Monstro::iniciaAnimacao(){
    this->timerAnimacao.restart();
}

void Monstro::initFisica(){
    this->gravidade = 4.f;
    this->VelMaxY = 10.f;
}


Monstro::Monstro(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    this->initFisica();
    STATE = parado;
}

Monstro::~Monstro(){

}

const sf::FloatRect Monstro::getGlobalBounds()const{
    return this->sprite.getGlobalBounds();
}

void Monstro::setPosicao(const float x, const float y){
    this->sprite.setPosition(x, y);
}

void Monstro::resetVelY(){
    this->velocidade.y = 0.f;
}

void Monstro::move(const float x, const float y){
    this->sprite.move(x,y);
}


void Monstro::updateFisica(){
    //GRAVIDADE
    this->velocidade.y += 1.0 * this->gravidade;
    if (std::abs(this->velocidade.y) >  this->VelMaxY){
        this->velocidade.y = this->VelMaxY * ((this->velocidade.y < 0.f) ? -1.f : 1.f);
    }
	this->sprite.move(this->velocidade.x, velocidade.y);
}

void Monstro::upadateMovimento(){

    
    
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
    }/*else if (this->STATE == andando_direita)
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
    }
    else if (this->estadoAnimacao == andando_esquerda)
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
    }*/
    STATE = parado;    
}


void Monstro::update(){
    this->updateFisica();
    this->upadateMovimento();
    this->uptadeAnimacao();
}

void Monstro::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}