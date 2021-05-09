#include "MenuLevel.h"

void MenuLevel::iniciaBotao(){

    this->btns["FASE1"] = new Botao(300,550, 200,80, "Level Um", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));

    this->btns["FASE2"] = new Botao(300,650, 200,80, "Level Dois", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));

    this->btns["SAIR"] = new Botao(300,750, 200,80, "Sair", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
}

void MenuLevel::iniciaBackground(){
    if (!this->texture.loadFromFile("Textures/Background/bg.png"))
        printf("BACKGROUND NÃO CARREGADO\n");
    
    this->background.setTexture(this->texture);
    this->background.setScale(6.f,7.f);
}


void MenuLevel::iniciaTitulo(){
    this->titulo.setFont(this->fonte);
    this->titulo.setString("Selecione o Level:");
    this->titulo.setCharacterSize(100);
    this->titulo.setColor(sf::Color(250,250,250,250));
    this->titulo.setPosition(sf::Vector2f(300,200));
}

MenuLevel::MenuLevel(sf::RenderWindow *window, std::stack<State*>* states):State(window, states){    
    iniciaTitulo();
    iniciaBackground();
    iniciaBotao();
}

MenuLevel::~MenuLevel()
{
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it!= this->btns.end(); ++it)
    { 
        delete it->second;
    }

}

void MenuLevel::updateBotao(){
    for (auto &it : this->btns)
    {
        it.second->update(this->mousePosView);
    }

    // SAIR DO JOGO
    if (this->btns["SAIR"]->isPressed()){
        this->quit = true;
    }else if (this->btns["FASE1"]->isPressed()){
        // PUSH NOVO STATE
        this->states->push(new LevelPrincipal(this->window, this->states));
        printf("botao  inicar precionado\n");
    }else if (this->btns["FASE2"]->isPressed())
    {
        this->states->push(new LevelFinal(this->window, this->states));
        printf("botao  placar precionado\n");
    }
    

}

void MenuLevel::update(){
    this->updateKeybinds();
    this->updateMousePosition();
    std::cout<<this->mousePosWindow.x <<", "<< this->mousePosWindow.y << std::endl;
    updateBotao();
}

void MenuLevel::renderBotao(sf::RenderTarget &target){
    for (auto &it : this->btns)
    {
        it.second->render(target);
    } 
}

void MenuLevel::render(sf::RenderTarget &target){
    target.draw(this->background);
    renderBotao(target);
    target.draw(this->titulo);
}


