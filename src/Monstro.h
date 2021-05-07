#include "Inimigos.h"

class Monstro : public Inimigos{
private:




    //status do Monstro


    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();


public:
    Monstro();
    ~Monstro();






    void upadateMovimento();
    void uptadeAnimacao();

};
