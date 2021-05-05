#include "Menu.h"

class GerenciadorGrafico;
class MenuPrincipal: public Menu{
private:
    Botao iniciar;
    Botao continuar;
    Botao rankin;
    Botao carregar;
    Botao selecionarFase;

    Botao primeiraFase;
    Botao segundaFase;

    Botao sair;
public:
    MenuPrincipal();
    ~MenuPrincipal();
    void desenhar(sf::RenderWindow *Janela); 
    void iniciarJogo(sf::RenderWindow *Janela);
    void continuarJogo(sf::RenderWindow *Janela);
    void carregarJogo(sf::RenderWindow *Janela);
    void ranking(sf::RenderWindow *Janela);
    void selecFase(sf::RenderWindow *Janela);
};