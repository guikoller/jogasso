#include <SFML/Graphics.hpp>

class Botao{
    private:
        sf::RectangleShape retangulo;
        sf::Text texto;
        sf::Font localFont;
        sf::Color corTexto;
        sf::Color corRetangulo;
    public:
        Botao(){}
        ~Botao(){}
        
        Botao(sf::Vector2f tamBotao,const char *textoBotao,sf::Color corText,sf::Color corReta):
            retangulo(),texto(),localFont(),corTexto(),corRetangulo()
            {
            retangulo.setSize(tamBotao);
            texto.setString(textoBotao);
            corTexto = corText;
            corRetangulo = corReta;
            retangulo.setFillColor(corRetangulo);
            texto.setFillColor(corTexto);

        }
        void setPosicao(sf::Vector2f pos){
            retangulo.setPosition(pos);
            float posX = pos.x + ( retangulo.getSize().x / 2 );
            float posY = pos.y + ( retangulo.getSize().y / 2 );
            texto.setPosition(sf::Vector2f(posX,posY));
        }
        void setCorTexto(sf::Color cor){
            texto.setFillColor(cor);
        }
        void setCorBotao(sf::Color cor){
            retangulo.setFillColor(cor);
        }
        void setTexto(const char *textoBotao){
            texto.setString(textoBotao);
        }
        void setTamBotao(sf::Vector2f tamanho){
            retangulo.setSize(tamanho);
        }
        bool precionado(sf::RenderWindow *Janela){
            sf::Vector2i pos = sf::Mouse::getPosition(*Janela);
            float diaSupEsq = retangulo.getPosition().x;
            float diaInfDir = retangulo.getPosition().y;
        }
        void desenhar(sf::RenderWindow *Janela){
            Janela->draw(retangulo);
            Janela->draw(texto);
        }
};