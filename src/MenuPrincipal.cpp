#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow *window):State(window){

    this->background.setSize(sf::Vector2f((float)window->getSize().x, (float)window->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::render(sf::RenderTarget &target){
    target.draw(this->background);
}


