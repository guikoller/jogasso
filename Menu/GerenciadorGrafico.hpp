#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class GerenciadorGrafico{
private:
    sf::RenderWindow *Janela;
    sf::Color c;
    sf::Event event;
public:
    GerenciadorGrafico():c(sf::Color::Black){
        Janela = new sf::RenderWindow();
        Janela->create(sf::VideoMode(1920,1080),"Test Menu");
        Janela->setFramerateLimit(30);
    }
    ~GerenciadorGrafico(){delete(Janela);}
    void desenhar(sf::CircleShape *c)   {Janela->draw(*c)}
    void desenhar(sf::RectangleShape *r){Janela->draw(*r)}
    void desenhar(sf::Shape *s)         {Janela->draw(*s)}
    void desenhar(sf::Text *t)          {Janela->draw(*t)}
    void clear(void){  
        if(janelaAberta()){
            if(Janela->pollEvent(event))
                if (event.type == sf::Event::Closed)
                    Janela->close();
            Janela->clear(c);
        }
        }
    void display(void){  
        if(janelaAberta()){
            if(Janela->pollEvent(event))
                if (event.type == sf::Event::Closed)
                    Janela->close();
            Janela->display();
        }
        }
    bool janelaAberta(void){return Janela->isOpen();}
    void fecharJanela(void){Janela->close();}
};