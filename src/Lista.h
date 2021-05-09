#include "Elemento.h"


template <class TL> class Lista{
private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
        int len;
public:
        Lista();
        ~Lista();

        int getLen() { return len; }

        TL* getItem(int pos)
        {
            Elemento<TL> *temp = pPrimeiro;
            if(pos == 0)
                return temp->getItem();
            for(int i = 0; i < pos; i++)
            {
                temp = temp->getProx();
            }
            return temp->getItem();
        }

        void incluir(TL* item)
        {
            if(pPrimeiro == nullptr)
            {
                pPrimeiro = new Elemento<TL>;
                pPrimeiro->setItem(item);
                pUltimo = pPrimeiro;
            }
            else
            {
                Elemento<TL>* temp = new Elemento<TL>;
                temp->setItem(item);
                pUltimo->setProx(temp);
                pUltimo = temp;
            }
            len++;
        }

        void excluir(TL* item)
        {
            Elemento<TL>* temp = pPrimeiro;
            Elemento<TL>* tempAnt = nullptr;

            while(temp->getItem() != item)
            {
                tempAnt = temp;
                temp = temp->getProx();
            }
            if(temp == pPrimeiro)
            {
                pPrimeiro = temp->getProx();
            }
            else if(temp == pUltimo)
            {
                tempAnt->setProx(nullptr);
                pUltimo = tempAnt;
            }
            else
            {
                tempAnt->setProx(temp->getProx());
            }
            delete temp;
            len--;
        }
};

template<class TL>
inline Lista<TL>::Lista()
{
    pPrimeiro = nullptr;
    pUltimo = nullptr;
    len = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{

}