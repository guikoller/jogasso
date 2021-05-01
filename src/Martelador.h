#include "Jogavel.h"

class Martelador: protected Jogavel{
private:
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();
 public:
    Martelador();
    ~Martelador();
    virtual void move(const float x, const float y);
    virtual void upadateMovimento();
    virtual void uptadeAnimacao();
};
