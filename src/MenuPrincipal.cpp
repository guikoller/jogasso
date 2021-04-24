#include "MenuPrincipal.h"
#include "GerenciadorGrafico.h"

MenuPrincipal::~MenuPrincipal(){

}

void MenuPrincipal::desenhar(GerenciadorGrafico *p){
    p->clear();
    p->desenhaImagem(&planoFundoSprite);
    p->display();
    
}

void MenuPrincipal::ranking(GerenciadorGrafico *p){}
void MenuPrincipal::carregarJogo(GerenciadorGrafico *p){}
void MenuPrincipal::continuarJogo(GerenciadorGrafico *p){}
void MenuPrincipal::iniciarJogo(GerenciadorGrafico *p){}