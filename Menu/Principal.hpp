#include "MenuPrincipal.hpp"
#include "GerenciadorGrafico.hpp"

class Principal{
    private:
    MenuPrincipal mPrincipal;
    GerenciadorGrafico tela;
    public:
    Principal():mPrincipal(),tela(){}
    ~Principal(){}
    void executar(){
        while (tela.janelaAberta()){
            mPrincipal.desenhar(&tela);
        }
        }

};



