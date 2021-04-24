#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class GerenciadorGrafico{
private:
    sf::RenderWindow *Janela;
    sf::Color c;
    sf::Event event;
    void atualizaEvento(void){
        Janela->pollEvent(event);
    }
public:
    GerenciadorGrafico():c(sf::Color::Black){
        Janela = new sf::RenderWindow();
        Janela->create(sf::VideoMode(1920,1080),"Test Menu");
        Janela->setFramerateLimit(30);
    }
    ~GerenciadorGrafico(){delete(Janela);}
    void desenhar(sf::CircleShape *c)   {Janela->draw(*c);}
    void desenhar(sf::RectangleShape *r){Janela->draw(*r);}
    void desenhar(sf::Shape *s)         {Janela->draw(*s);}
    void desenhar(sf::Text *t)          {Janela->draw(*t);}
    void desenhar(sf::Sprite *s)        {Janela->draw(*s);}
    void clear(void)    {Janela->clear(); }
    void display(void)  {Janela->display();}
    bool janelaAberta(void){return Janela->isOpen();}
    bool botaoMousePressionado(void){
        while (Janela->pollEvent(event))
            if(event.type == sf::Event::MouseButtonPressed)
                return true;
        return false;}
    void fecharJanelaPressionado(){
        while (Janela->pollEvent(event))
            if(event.type == sf::Event::Closed)
                Janela->close();}
    void fechraJanela(void){Janela->close();}
    sf::Vector2i getPosicaoMouse(void){return sf::Mouse::getPosition(*Janela);}
    
};