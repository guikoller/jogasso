#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Entidade.h"
#include "Personagem.h"
#include "Espadachim.h"

#include "LevelBase.h"
#include "LevelPrincipal.h"

#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"


class Jogo{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimizazão
    //Partes de acordo a UML, vou fazer assim e voce muda as funcoes para as novas partes
    
    GerenciadorGrafico *janela;
    GerenciadorEventos *eventos;


    //
    sf::Clock dtClock;
    float dt;

    LevelPrincipal *level;

    void initEntidade();
    void initWindow();
public:
    Jogo(/* args */);
    ~Jogo();
    
    //Functions
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
    void update();
    void updateDT();
    void updateSFMLevents();
    void updateColisao();
    void render();
    void executar();
};


