#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"



class Menu{
protected:
    sf::Text texto;
    sf::Sprite planoFundoSprite;
    sf::Texture selecionarPlano;
    sf::Font selecionarFonte;
public:
    Menu():planoFundoSprite(),texto(),selecionarPlano(),selecionarFonte(){
        selecionarFonte.loadFromFile("font.ttf");
        texto.setCharacterSize(28);
        texto.setFont(selecionarFonte);
        selecionarPlano.loadFromFile("bg.jpg");
        planoFundoSprite.setTexture(selecionarPlano);
        planoFundoSprite.setOrigin(sf::Vector2f(0,0));
        planoFundoSprite.setPosition(sf::Vector2f(0,0));
        }
    virtual ~Menu(){}
    virtual void desenhar(){};
};