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
public:
    MenuPrincipal():Menu(),
    iniciar(),continuar(),rankin(),carregar(){
        iniciar.botaoPadrao01("Iniciar");
        continuar.botaoPadrao01("Continuar");
        rankin.botaoPadrao01("Ranking");
        carregar.botaoPadrao01("Carregar");
        primeiraFase.botaoPadrao01("Primeira Fase");
        segundaFase.botaoPadrao01("Segunda Fase");
        selecionarFase.botaoPadrao01("Selecionar Fase");

        iniciar.setPosicao({0,300});
        continuar.setPosicao({0,350});
        rankin.setPosicao({0,400});
        carregar.setPosicao({0,450});
        selecionarFase.setPosicao({0,500});
        primeiraFase.setPosicao({0,300});
        segundaFase.setPosicao({0,350});

    }
    ~MenuPrincipal();
    void desenhar(sf::RenderWindow *Janela); 
    void iniciarJogo(sf::RenderWindow *Janela);
    void continuarJogo(sf::RenderWindow *Janela);
    void carregarJogo(sf::RenderWindow *Janela);
    void ranking(sf::RenderWindow *Janela);
    void selecFase(sf::RenderWindow *Janela);
};