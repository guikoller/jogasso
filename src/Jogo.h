#include <stack>
#include "LevelPrincipal.h"
#include "LevelFinal.h"


class Jogo{
private:
    sf::RenderWindow window;
    sf::Event event;//checa eventos da jenela como teclas pressionadas comando de fechamendo, minimizazão

    // MenuPrincipal menu;

    sf::Clock dtClock;
    float dt;
    
    std::stack <State*> states;


    void initWindow();
    void initStates();
public:
    Jogo(/* args */);
    ~Jogo();
    
    //Functions
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
    void update();
    void updateDT();
    void updateSFMLevents();
    void updateState();
    void render();
    void executar();
};


