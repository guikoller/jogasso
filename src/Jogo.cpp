#include "Jogo.h"


void Jogo::initWindow(){
    this->window.create(sf::VideoMode(1280,720),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(144);
}

void Jogo::initEntidade(){
    this->jogador  = new Entidade();
}


Jogo::Jogo(){
    this->initWindow();
    this->initEntidade();
}

Jogo::~Jogo(){
    delete this->jogador;
}

void Jogo::render(){
    this->window.clear();
    //renderizão do jogo vai aqui

    this->renderEntidade();

    //
    this->window.display();
}


void Jogo::renderEntidade(){
    this->jogador->render(this->window);
}


void Jogo::updateEntidade(){
    this->jogador->update();
}

const sf::RenderWindow& Jogo::getWindow() const{//retorna estado da janela aberta ou fechada
    return this->window; 
}

void Jogo::update(){
    //pega todos o eventos da janela
    while (this->window.pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)//se a janela for fechada
            this->window.close();
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
            this->window.close();// checa se uma tecla foi precionada e se foi, se é esc                   
    }
    
    this->updateEntidade();
    this->updateColisao();

}

void Jogo::updateColisao(){
    //colisão com o fundo da tela
    if(this->jogador->getGlobalBounds().top + this->jogador->getGlobalBounds().height > this->window.getSize().y){
        this->jogador->resetVelY();
        this->jogador->setPosicao(this->jogador->getGlobalBounds().left,
            this->window.getSize().y - this->jogador->getGlobalBounds().height
        );
    }
}

void Jogo::rodar(){
    while (this->getWindow().isOpen())
    {
        this->update();
        this->render();
    }
}