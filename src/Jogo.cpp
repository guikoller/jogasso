#include "Jogo.h"
#include "Collision.h"


void Jogo::initWindow(){

    this->window.create(sf::VideoMode(1600,1010),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(144);
    this->window.setVerticalSyncEnabled(true);
}
void Jogo::initEntidade(){
    this->level = new LevelPrincipal();
}
void Jogo::initStates(){
    this->states.push(new GameState(this->window));
}

Jogo::Jogo():menu(){
    this->initWindow();
    this->initStates();
    this->initEntidade();
}
Jogo::~Jogo(){
    delete level;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    
}


//UPDATES////////////////////////////////////////////
void Jogo::updateDT(){
    this->dt = this->dtClock.restart().asSeconds();
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
void Jogo::updateState(){
    if(!this->states.empty())
        this->states.top()->update();
}
void Jogo::update(){
    this->updateSFMLevents();
    this->updateDT();
    this->level->update();
}

//RENDER/////////////////////////////////////////////

const sf::RenderWindow& Jogo::getWindow() const{//retorna estado da janela aberta ou fechada
    return this->window; 
}

void Jogo::render(){
    this->window.clear();
    //renderização do jogo vai aqui
    
    if(!this->states.empty())
        this->states.top()->render(this->window);
    
    this->level->render(this->window);

    //
    this->window.display();
}

/////////////////////////////////////////////////////

void Jogo::executar(){
    //menu.desenhar(&window);
    while (this->getWindow().isOpen())
    {
        this->update();
        this->render();
    }
}