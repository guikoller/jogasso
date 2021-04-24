#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "GerenciadorGrafico.h"


class Menu{
protected:
    sf::Sprite planoFundoSprite;
    sf::Texture selecionarPlano;

    //-------------------------------------------Botoes
    class Botao{
        private:
            sf::RectangleShape retangulo;
            sf::Text texto;
            sf::Font localFont;
            sf::Color corTexto;
            sf::Color corRetangulo;
            sf::Color efeito;
        public:
            Botao():retangulo(),texto(),localFont(),corTexto(),corRetangulo(),efeito(){}
            ~Botao(){}
            Botao(sf::Vector2f tamBotao,const char *textoBotao,sf::Color corText,sf::Color corReta):
                retangulo(),texto(),localFont(),corTexto(corText),corRetangulo(corReta)
                {
                retangulo.setSize(tamBotao);
                localFont.loadFromFile("font.ttf");
                retangulo.setFillColor(corRetangulo);

                texto.setFillColor(corTexto);
                texto.setString(textoBotao);
                texto.setFont(localFont);
                texto.setCharacterSize(14);
            }
            void botaoPadrao01(const char *text){
                corRetangulo = sf::Color(79,165,173);
                corTexto = sf::Color::Black;
                efeito = sf::Color::White;

                localFont.loadFromFile("../Font/font.ttf");
                retangulo.setSize({200,35});
                retangulo.setFillColor(corRetangulo);

                texto.setFillColor(corTexto);
                texto.setString(text);
                texto.setFont(localFont);
                texto.setCharacterSize(14);
            }
            void setPosicao(sf::Vector2f pos){
                retangulo.setPosition(pos);
                float posX = pos.x + ( retangulo.getSize().x / 2 );
                float posY = pos.y + ( retangulo.getSize().y / 2 );
                texto.setPosition({posX,posY});
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
            bool mouseSobreBotao(GerenciadorGrafico *p){
                float posX = p->getPosicaoMouse().x;
                float posY = p->getPosicaoMouse().y;
                
                float diaSupEsqX = retangulo.getPosition().x;
                float diaSupEsqY = retangulo.getPosition().y;
                
                float diaInfDirX = retangulo.getPosition().x + retangulo.getSize().x;
                float diaInfDirY  = retangulo.getPosition().y + retangulo.getSize().y;

                if( (posX > diaSupEsqX) && (posY > diaSupEsqY ) && (posX < diaInfDirX ) && (posY < diaInfDirY) ){
                    retangulo.setFillColor(efeito);
                    return true;
                }
                retangulo.setFillColor(corRetangulo);
                return false;
            }
            void setCorEfeito(sf::Color cor){
                efeito = cor;
            }
            bool pressionado(GerenciadorGrafico *p){
                if( mouseSobreBotao(p) && p->botaoMousePressionado())
                    return true;
                return false;
            }
            void desenhar(GerenciadorGrafico *p){
                p->desenhar(&retangulo);
                p->desenhar(&texto);
            }
    };
    
public:
    Menu():planoFundoSprite(),selecionarPlano(){
        selecionarPlano.loadFromFile("bg.jpg");
        planoFundoSprite.setTexture(selecionarPlano);
        planoFundoSprite.setOrigin(sf::Vector2f(0,0));
        planoFundoSprite.setPosition(sf::Vector2f(0,0));
        }
    virtual ~Menu(){}
    virtual void desenhar(){};
};