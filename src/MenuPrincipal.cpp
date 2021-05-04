#include "MenuPrincipal.h"

MenuPrincipal::~MenuPrincipal(){
}

void MenuPrincipal::desenhar(sf::RenderWindow *Janela){
    bool select = false;
    while(!select && Janela->isOpen()){
        Janela->clear();

        iniciar.desenhar(Janela);
        continuar.desenhar(Janela);
        carregar.desenhar(Janela);
        rankin.desenhar(Janela);
        
        p->display();
        if(iniciar.pressionado(Janela)){
            iniciarJogo(Janela);
            select = true;
        }
        if(continuar.pressionado(Janela)){
            continuarJogo(Janela);
            select = true;
        }
        if(rankin.pressionado(Janela)){
            carregarJogo(Janela);
            select = true;
        }
        if(carregar.pressionado(Janela)){
            ranking(Janela);
            select = true;
        }
    }
}

void MenuPrincipal::iniciarJogo(sf::RenderWindow *Janela){
    
}
void MenuPrincipal::continuarJogo(sf::RenderWindow *Janela){
    printf("continuou");
    desenhar(p);
}
void MenuPrincipal::carregarJogo(sf::RenderWindow *Janela){
    printf("carregou");
    desenhar(p);
}
void MenuPrincipal::ranking(sf::RenderWindow *Janela){
    printf("vendo ranking");
    desenhar(p);
}
void MenuPrincipal::selecFase(sf::RenderWindow *Janela){
    bool select = false;
    while(!select && Janela->isOpen()){
        Janela->clear();

        primeiraFase.desenhar(Janela);
        segundaFase.desenhar(Janela);
        
        p->display();
        if(primeiraFase.pressionado(Janela)){
            //Funcao que carrega primeira fase
            select = true;
        }
        if(segundaFase.pressionado(Janela)){
            //Funcao que carrega segunda fase
            select = true;
        }
    }
}