#include "Lista.h"
#pragma once
#include "Monstro.h"

class ListaInimigo{
    private:
        Lista<Monstro>* list;
    public:
    ListaInimigo(){ list = new Lista<Monstro>();}
    ~ListaInimigo();
    void adicionar(Monstro* p){list->adicionar(p);}
    void remover(int chave){list->remover(chave);}
    Monstro* operator[](int chave){
        return list->getTipo(chave);
    }
    Monstro* getMonstro(int chave){
        return list->getTipo(chave);
    }
};