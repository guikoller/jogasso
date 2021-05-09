#pragma once
#include <SFML/Graphics.hpp>



class Botao{
private:
    enum button_state{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};
    
    short unsigned int btn_state;

    bool precionado;
    bool hover;

    sf::RectangleShape shape;
    sf::Font* fonte;
    sf::Text texto;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Botao(float x, float y, float largura, float altura, std::string texto, sf::Font* fonte, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Botao();

    //acessores
    bool isPressed();

    //funções
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget &target);
};


