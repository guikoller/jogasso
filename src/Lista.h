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
        void adicionar(Tipo* p){
            if(primeiro != NULL){
                Elemento<Tipo>* novo = new Elemento<Tipo>();
                novo->setTipo(p);
                atual->setNext(novo);
                novo->setPrev(atual);
                novo->setNext(NULL);
                atual = novo;
            }
            else{
                primeiro = new Elemento<Tipo>();
                primeiro->setTipo(p);
                primeiro->setNext(NULL)
                primeiro->setPrev(NULL);
                atual = primeiro;
            }
        }
        void remover(int chave){
            Elemento<Tipo> *aux = primeiro;
            int i = 0 ;
            while(i != chave && aux != NULL){
                aux = aux->getNext();
                i++;
            }
            if(aux != NULL){
                Elemento<Tipo>* anterior = aux->getPrev();
                anterior->setNext(aux->getNext());
                Elemento<Tipo>* proximo = aux->getNext();
                proximo->setPrev(anterior);
                delete(aux);
            }
            else{
                //
                //cout<<"Elemento nao consta na lista."<<endl;
            }
        }
        Tipo* getTipo(int chave){
            Elemento<Tipo>* aux = primeiro;
            int i = 0;
            while(i != chave && aux != NULL){
                aux = aux->getNext();
                i++;
            }
            if(i == chave)
                return aux->getTipo();
            //exit(1);
            //cout<<"Acesso invalido a lista."<<endl;
            return NULL;
        }
        void apagar(){
            while(primeiro != NULL){
                delete(atual);
                atual = atual->getPrev();
            }
        }
};