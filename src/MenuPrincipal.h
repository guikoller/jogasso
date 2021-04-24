#include "Menu.h"

class GerenciadorGrafico;
class MenuPrincipal: public Menu{
    public:
    MenuPrincipal():Menu(){}
    ~MenuPrincipal();
    void desenhar(GerenciadorGrafico *p); 
    void ranking(GerenciadorGrafico *p);
    void carregarJogo(GerenciadorGrafico *p);
    void continuarJogo(GerenciadorGrafico *p);
    void iniciarJogo(GerenciadorGrafico *p);
};

