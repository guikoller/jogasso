#include "Menu.h"

class GerenciadorGrafico;
class MenuPrincipal: public Menu{
    private:
    Botao iniciar;
    Botao continuar;
    Botao rankin;
    Botao carregar;
    public:
    MenuPrincipal():Menu(),
    iniciar(),continuar(),rankin(),carregar(){
        iniciar.botaoPadrao01("Iniciar");
        continuar.botaoPadrao01("Continuar");
        rankin.botaoPadrao01("Ranking");
        carregar.botaoPadrao01("Carregar");
        iniciar.setPosicao({0,300});
        continuar.setPosicao({0,350});
        rankin.setPosicao({0,400});
        carregar.setPosicao({0,450});
    }
    ~MenuPrincipal();
    void desenhar(GerenciadorGrafico *p); 
    void iniciarJogo(GerenciadorGrafico *p);
    void continuarJogo(GerenciadorGrafico *p);
    void carregarJogo(GerenciadorGrafico *p);
    void ranking(GerenciadorGrafico *p);
};