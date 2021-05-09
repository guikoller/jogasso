#include <stdio.h>

template <class TE> class Elemento{
private:
        Elemento<TE>* pProx;
        //Elemento<TE>* prev;
        TE* item;
public:
        Elemento();
        ~Elemento();

        void setProx(Elemento<TE>* pProx) { this->pProx = pProx; }
        void setItem(TE* item) { this->item = item; }
        Elemento<TE>* getProx() { return pProx; }
        TE* getItem() { return item; }
};

template<class TE>
inline Elemento<TE>::Elemento()
{
    pProx = nullptr;
    item = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{

}