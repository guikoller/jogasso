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

void Jogador::initFisica(){
    this->velMax = 5.f;
    this->velMin = 0.5f;
    this->aceleracao = 0.7f;
    this->desaceleracao= 0.95f;
    this->gravidade = 4.f;
    this->VelMaxY = 10.f;
}


Jogador::Jogador(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    this->initFisica();
}

Jogador::~Jogador(){

}

const sf::FloatRect Jogador::getGlobalBounds()const{
    return this->sprite.getGlobalBounds();
}

void Jogador::setPosicao(const float x, const float y){
    this->sprite.setPosition(x, y);
}

void Jogador::resetVelY(){
    this->velocidade.y = 0.f;
}

void Jogador::move(const float x, const float y){
    // aceleração
    this->velocidade.x += x * this->aceleracao;
    

    //limite de velocidade
    if (std::abs(this->velocidade.x) >  this->velMax)
        this->velocidade.x = this->velMax * ((this->velocidade.x < 0.f) ? -1.f : 1.f);    

}


void Jogador::updateFisica(){
    //GRAVIDADE
    this->velocidade.y += 1.0 * this->gravidade;
    if (std::abs(this->velocidade.y) >  this->VelMaxY)
        this->velocidade.y = this->VelMaxY * ((this->velocidade.y < 0.f) ? -1.f : 1.f);
    
    
    // desaceleração
    this->velocidade *= this->desaceleracao;

    //limite de desaceleração
    if (std::abs(velocidade.x) < this->velMin)
        this->velocidade.x = 0.f;
    if (std::abs(velocidade.y) < this->velMin)
        this->velocidade.y = 0.f;
    

    this->sprite.move(this->velocidade);
}

void Jogador::upadateMovimento(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->move(-1.f,0.f);//Esquuerda
        this->estadoAnimacao = MOVE_ESQUERDA;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->move(1.f,0.f);//Direita
        this->estadoAnimacao = MOVE_DIREITA;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->move(0.f,-1.f);//Cima
        this->estadoAnimacao = PULANDO;
    }// }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
    //     this->move(0.f,2.f);//Baixo
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
    
    this->estadoAnimacao = ESTADOS_ANIMACOES::PARADO;
      
    
}


void Jogador::update(){
    this->updateFisica();
    this->upadateMovimento();
    this->uptadeAnimacao();
}

void Jogador::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}