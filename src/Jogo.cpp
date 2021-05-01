#include "Jogo.h"
#include "Collision.h"


void Jogo::initWindow(){
    this->window.create(sf::VideoMode(1600,1010),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(144);
    this->window.setVerticalSyncEnabled(true);
}

void Jogo::initEntidade(){
    this->martelador  = new Martelador();
    // this->martelador->setPosicao(128,128);
    this->monstro = new Monstro();
    this->mapa = new TileMap();
}


Jogo::Jogo(){
    this->initWindow();
    this->initEntidade();
}

Jogo::~Jogo(){
    delete this->martelador;
    delete this->monstro;
    delete this->mapa;
}

/////////////////////////////////////////////////////
//UPDATES////////////////////////////////////////////
/////////////////////////////////////////////////////
void Jogo::updateDT(){
    this->dt = this->dtClock.restart().asSeconds();
}


void Jogo::updateEntidade(){
    this->martelador->update();
    this->monstro->update();
}


void Jogo::updateColisao(){
    //colisão com o fundo da tela
    // if(this->martelador->getPosicao().y + this->martelador->getGlobalBounds().height > this->window.getSize().y){
    //     this->martelador->resetVelY();
    //     this->martelador->setPosicao(
    //         this->martelador->getPosicao().x,
    //         this->window.getSize().y - this->martelador->getGlobalBounds().height
    //     );
    // }


    if(this->monstro->getGlobalBounds().top + this->monstro->getGlobalBounds().height > this->window.getSize().y){
        this->monstro->resetVelY();
        this->monstro->setPosicao(this->monstro->getGlobalBounds().left,
            this->window.getSize().y - this->monstro->getGlobalBounds().height
        );
    }
    if (Collision::PixelPerfectTest(this->martelador->getSprite(),this->monstro->getSprite()))
    {
        printf("Colidiu\n");
        this->martelador->resetVelX();

    }else{
        printf("não Colidiu\n");
    }

    for (int i = 0; i < this->mapa->getLargura(); i++)
    {
        for (int j = 0; j < this->mapa->getAltura(); j++)
        {
             if (Collision::PixelPerfectTest(this->martelador->getSprite(),this->mapa->getSprite(i,j))){
                if (this->mapa->getSolido(i, j))
                {
                    this->martelador->resetVelY();
                    this->martelador->setPosicao(
                        this->martelador->getPosicao().x,
                        this->mapa->getSprite(i,j).getPosition().y - this->martelador->getSprite().getTextureRect().height - 32
                    );
                    // printf("Colidiu com o chão\n");
                }
            }
        }
        
    }
    
    
        
}
void Jogo::updateSFMLevents(){
    //pega todos o eventos da janela
    while (this->window.pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)//se a janela for fechada
            this->window.close();
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
            this->window.close();// checa se uma tecla foi precionada e se foi, se é esc                   
    }
}

void Jogo::update(){
    this->updateSFMLevents();
    this->updateDT();
    this->updateEntidade();
    this->updateColisao();
}
/////////////////////////////////////////////////////
//RENDER/////////////////////////////////////////////
/////////////////////////////////////////////////////
const sf::RenderWindow& Jogo::getWindow() const{//retorna estado da janela aberta ou fechada
    return this->window; 
}
void Jogo::render(){
    this->window.clear();
    //renderizão do jogo vai aqui

    this->renderEntidade();

    //
    this->window.display();
}
void Jogo::renderEntidade(){
    this->mapa->render(this->window);
    this->martelador->render(this->window);
    this->monstro->render(this->window);
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void Jogo::rodar(){
    while (this->getWindow().isOpen())
    {
        this->update();
        this->render();
    }
}