#include "Elemento.h"


/*
Poderiamos utilizar uma solução diferente como duas listas distintas, sendo cada uma composta por duas classes na forma abaixo ...
ListaObstaculos e LObstaculos (Ambas classes).
Optei por essa solução pois achei interessante ter listas de uso genérico, e memoria não é um problema neste caso específico
(Como exite apenas o .h, os bjetos não compartilhão seus metodos, cada um tem sua cópia)
*/

template <class Tipo>
class Lista{
    private:
        Elemento<Tipo>* primeiro;
        Elemento<Tipo>* atual;
    public:
        Lista():primeiro(NULL),atual(NULL){}
        ~Lista(){}
        void adicionar(Tipo* p , int chave);
        void remover(int chave);
        Tipo* getTipo(int chave){
            Elemento<Tipo>* aux = primeiro;
            while(aux != NULL){
                if(aux->getKey() == chave)
                    return aux->getTipo();
                aux = aux->getNext();
            }
            return NULL;
        }
};