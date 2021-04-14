#include "Entidade.h"


void Entidade::iniciaVariaveis(){
    this->estadoAnimacao = ESTADOS_ANIMACOES::PARADO;
}


void Entidade::iniciaTextura(){
    if (!this->texture.loadFromFile("Textures/Jogador/1/spritesheet.png")){
		std::cout << "ERROR::JOGADOR::TEXTURA NÃO CARREGADA!" << "\n";
	}
}

void Entidade::iniciaSprite(){
    this->sprite.setTexture(this->texture);
     
    this->frameAtual = sf::IntRect(0, 0, 96, 96);
    this->sprite.setTextureRect(this->frameAtual);
    this->sprite.setScale(3.f,3.f);

}

void Entidade::iniciaAnimacao(){
    this->timerAnimacao.restart();
}

void Entidade::initFisica(){
    this->velMax = 5.f;
    this->velMin = 0.5f;
    this->aceleracao = 0.7f;
    this->desaceleracao= 0.95f;
    this->gravidade = 4.f;
    this->VelMaxY = 10.f;
}


Entidade::Entidade(){
    this->iniciaVariaveis();
    this->iniciaTextura();
    this->iniciaSprite();
    this->iniciaAnimacao();
    this->initFisica();
}

Entidade::~Entidade(){

}

const sf::FloatRect Entidade::getGlobalBounds()const{
    return this->sprite.getGlobalBounds();
}

void Entidade::setPosicao(const float x, const float y){
    this->sprite.setPosition(x, y);
}

void Entidade::resetVelY(){
    this->velocidade.y = 0.f;
}

void Entidade::move(const float x, const float y){
    // aceleração
    this->velocidade.x += x * this->aceleracao;
    

    //limite de velocidade
    if (std::abs(this->velocidade.x) >  this->velMax)
        this->velocidade.x = this->velMax * ((this->velocidade.x < 0.f) ? -1.f : 1.f);    

}


void Entidade::updateFisica(){
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

void Entidade::upadateMovimento(){

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

void Entidade::uptadeAnimacao(){
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


void Entidade::update(){
    this->updateFisica();
    this->upadateMovimento();
    this->uptadeAnimacao();
}

void Entidade::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}