#include "Inimigo.h"

class Esqueleto : public Inimigo{
private:
    //status do Esqueleto


    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();


public:
    Esqueleto();
    ~Esqueleto();

    void upadateMovimento() override;
    void uptadeAnimacao() override;

};
