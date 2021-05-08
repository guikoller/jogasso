#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow *window):State(window){

    this->background.setSize(sf::Vector2f((float)window->getSize().x, (float)window->getSize().y));
    this->background.setFillColor(sf::Color::Blue);

    this->btn = new Botao(600,450, 200,80, "Iniciar", &this->fonte,
    sf::Color(200,200,200,200), 
    sf::Color(200,200,200,100), 
    sf::Color(200,200,200,50));

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


