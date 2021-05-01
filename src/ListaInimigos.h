#include "Lista.h"
#pragma once
#include "Monstro.h"

class ListaInimigo{
    private:
        Lista<Monstro>* list;
    public:
    ListaInimigo(){ list = new Lista<Monstro>();}
    ~ListaInimigo();
    void adicionar(Monstro* p,int chave){list->adicionar(Monstro* p,chave);}
    void remover(int chave){list->remover(chave);}
    Monstro* getMonstro(int chave){
        return list->getTipo(chave);
    }
};