#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow *window):State(window){

    
    if (!this->texture.loadFromFile("Textures/Background/bg.png"))    {
        printf("BACKGROUND NÃO CARREGADO\n");
    }

    this->background.setTexture(this->texture);
    this->background.setScale(6.f,7.f);
    
    
    this->btn = new Botao(600,450, 200,80, "Iniciar", &this->fonte,
    sf::Color(0,0,0,230), 
    sf::Color(10,10,10,200), 
    sf::Color(20,20,20,150));

}

MenuPrincipal::~MenuPrincipal()
{
    delete this->btn;
}

void MenuPrincipal::update(){
    this->updateKeybinds();
    this->updateMousePosition();
    std::cout<<this->mousePosWindow.x <<", "<< this->mousePosWindow.y << std::endl;
     this->btn->update(this->mousePosView);
}

void MenuPrincipal::render(sf::RenderTarget &target){
    target.draw(this->background);
    this->btn->render(target);
}


