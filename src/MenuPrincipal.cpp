#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal():Menu(),iniciar(),continuar(),rankin(),carregar(),selecionarFase(),primeiraFase(),segundaFase(),sair(){
        
        iniciar.botaoPadrao01("Iniciar");
        continuar.botaoPadrao01("Continuar");
        rankin.botaoPadrao01("Ranking");
        carregar.botaoPadrao01("Carregar");
        primeiraFase.botaoPadrao01("Primeira Fase");
        segundaFase.botaoPadrao01("Segunda Fase");
        selecionarFase.botaoPadrao01("Selecionar Fase");
        sair.botaoPadrao01("Sair do Jogo");

        iniciar.setPosicao({0,300});
        continuar.setPosicao({0,350});
        rankin.setPosicao({0,400});
        carregar.setPosicao({0,450});
        selecionarFase.setPosicao({0,500});
        sair.setPosicao({0,550});
        primeiraFase.setPosicao({0,300});
        segundaFase.setPosicao({0,350});

    }

MenuPrincipal::~MenuPrincipal(){
}

void MenuPrincipal::desenhar(sf::RenderWindow *Janela){
    bool select = false;
    while(!select && Janela->isOpen() && !sair.pressionado(Janela) ){
        Janela->clear();

        iniciar.desenhar(Janela);
        continuar.desenhar(Janela);
        carregar.desenhar(Janela);
        rankin.desenhar(Janela);
        sair.desenhar(Janela);
        
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