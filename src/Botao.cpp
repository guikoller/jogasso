#include "Botao.h"

Botao::Botao(float x, float y, float largura, float altura, std::string texto, sf::Font *fonte, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor){
    this->btn_state = BTN_IDLE;

    this->shape.setSize(sf::Vector2f(largura, altura));
    this->shape.setPosition(sf::Vector2f(x,y));

    this->fonte = fonte;
    this->texto.setFont(*this->fonte);
    this->texto.setString(texto);
    this->texto.setFillColor(sf::Color::White);
    this->texto.setCharacterSize(12);
    this->texto.setPosition(
        this->shape.getPosition().x /2.f - this->texto.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y /2.f - this->texto.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

Botao::~Botao(){}


const bool Botao::isPressed() const{
    if (this->btn_state = BTN_PRESSED)
        return true;

    return false;
}

void Botao::update(const sf::Vector2f mousePos){

    // ESTADO PADRÃO DO BOTÃO
    this->btn_state = BTN_IDLE;

    if (this->shape.getGlobalBounds().contains(mousePos)){
       //PASSOU MOUSE POR CIMA
       this->btn_state = BTN_HOVER;
       //APERTOU BOTÃO
       if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
           this->btn_state = BTN_PRESSED;
       }
    }

    switch (this->btn_state){
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->idleColor);
        break;
    case BTN_PRESSED:
        this->shape.setFillColor(this->idleColor);
        break;
    default:
        this->shape.setFillColor(sf::Color::Red);//não pra entrar aqui não
        break;
    }


}

void Botao::render(sf::RenderTarget &target){
    target.draw(this->shape);
}