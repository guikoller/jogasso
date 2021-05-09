#include "Inimigo.h"

class Goblin : public Inimigo{
private:
    //status do Goblin

    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();


public:
    Goblin();
    ~Goblin();
    
    void upadateMovimento();
    void uptadeAnimacao();
};
