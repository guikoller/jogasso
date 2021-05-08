#include "MenuPrincipal.h"

void MenuPrincipal::iniciaBotao(){

    this->btns["INICIAR"] = new Botao(700,550, 200,80, "Iniciar", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));

    this->btns["PLACAR"] = new Botao(700,650, 200,80, "Placar", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));

    this->btns["SAIR"] = new Botao(700,750, 200,80, "Sair", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
}

void MenuPrincipal::iniciaBackground(){
    if (!this->texture.loadFromFile("Textures/Background/bg.png"))
        printf("BACKGROUND NÃO CARREGADO\n");
    
    this->background.setTexture(this->texture);
    this->background.setScale(6.f,7.f);
}


void MenuPrincipal::iniciaTitulo(){
    this->titulo.setFont(this->fonte);
    this->titulo.setString("JOGASSO");
    this->titulo.setCharacterSize(300);
    this->titulo.setColor(sf::Color(250,250,250,250));
    this->titulo.setPosition(sf::Vector2f(150,100));
}

MenuPrincipal::MenuPrincipal(sf::RenderWindow *window, std::stack<State*>* states):State(window, states){    
    iniciaTitulo();
    iniciaBackground();
    iniciaBotao();
}

MenuPrincipal::~MenuPrincipal()
{
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it!= this->btns.end(); ++it)
    { 
        delete it->second;
    }
    

}

void MenuPrincipal::updateBotao(){
    for (auto &it : this->btns)
    {
        it.second->update(this->mousePosView);
    }

    // SAIR DO JOGO
    if (this->btns["SAIR"]->isPressed())
    {
        this->quit = true;
    }else if (this->btns["INICIAR"]->isPressed())
    {
        // PUSH NOVO STATE
        this->states->push(new LevelPrincipal(this->window, this->states));
        printf("botao  inicar precionado\n");
    }else if (this->btns["PLACAR"]->isPressed())
    {
        printf("botao  placar precionado\n");
    }
    

}

void MenuPrincipal::update(){
    this->updateKeybinds();
    this->updateMousePosition();
    std::cout<<this->mousePosWindow.x <<", "<< this->mousePosWindow.y << std::endl;
    updateBotao();
}

void MenuPrincipal::renderBotao(sf::RenderTarget &target){
    for (auto &it : this->btns)
    {
        it.second->render(target);
    } 
}

void MenuPrincipal::render(sf::RenderTarget &target){
    target.draw(this->background);
    renderBotao(target);
    target.draw(this->titulo);
}


