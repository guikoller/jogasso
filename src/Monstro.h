#include "Inimigo.h"

class Monstro : public Inimigo{
private:




    //status do Monstro


    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();


public:
    Monstro();
    ~Monstro();


    void upadateMovimento() override;
    void uptadeAnimacao() override;

};
