#include "Jogo.h"


void Jogo::initWindow(){
    this->window.create(sf::VideoMode(1280,720),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(144);
}

void Jogo::initJogador(){
    this->jogador  = new Jogador();
}


Jogo::Jogo(){
    this->initWindow();
    this->initJogador();
}

Jogo::~Jogo(){
    delete this->jogador;
}

void Jogo::render(){
    this->window.clear();
    //renderizão do jogo vai aqui

    this->renderJogador();

    //
    this->window.display();
}


void Jogo::renderJogador(){
    this->jogador->render(this->window);
}


void Jogo::updateJogador(){
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
    
    this->updateJogador();

}