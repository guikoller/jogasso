#include <stdio.h>

template <class Tipo>
class Elemento{
    private:
        Elemento<Tipo>*  next;
        Elemento<Tipo>* prev;
        Tipo* p;
    public:
        Elemento():next(NULL),prev(NULL),p(NULL){}
        /*  Tudo será alocado e desalocado em outras funcoes.   */
        ~Elemento(){}
        void setNext(Elemento<Tipo>* proximo){    
            if(proximo != NULL)
                next = proximo;
                }
        void setPrev(Elemento<Tipo>* anterior){
            if(anterior != NULL )
                prev = anterior;
        }
        void setTipo(Tipo* novo){
            p = novo;
        }

        Elemento<Tipo>* getPrev(void){    return prev;}
        Elemento<Tipo>* getNext(void){    return next;}
};