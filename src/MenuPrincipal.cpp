#include "MenuPrincipal.h"

MenuPrincipal::~MenuPrincipal(){
}

void MenuPrincipal::desenhar(GerenciadorGrafico *p){
    bool select = false;
    while(!select && p->janelaAberta()){
        p->clear();
        p->fecharJanelaPressionado();
        //p->desenhar(&planoFundoSprite);
        iniciar.desenhar(p);
        continuar.desenhar(p);
        carregar.desenhar(p);
        rankin.desenhar(p);
        
        p->display();
        if(iniciar.pressionado(p)){
            iniciarJogo(p);
            select = true;
        }
        if(continuar.pressionado(p)){
            continuarJogo(p);
            select = true;
        }
        if(rankin.pressionado(p)){
            carregarJogo(p);
            select = true;
        }
        if(carregar.pressionado(p)){
            ranking(p);
            select = true;
        }
    }
}

void MenuPrincipal::iniciarJogo(GerenciadorGrafico *p){
    printf("iniciou");
    p->fechraJanela();
}
void MenuPrincipal::continuarJogo(GerenciadorGrafico *p){
    printf("continuou");
    desenhar(p);
}
void MenuPrincipal::carregarJogo(GerenciadorGrafico *p){
    printf("carregou");
    desenhar(p);
}
void MenuPrincipal::ranking(GerenciadorGrafico *p){
    printf("vendo ranking");
    desenhar(p);
}