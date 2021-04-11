#pragma once
#include "Jogo.h"


int main()
{
    // srand(static_cast<unsigned>(time(0)));
    
    Jogo jogo;

    while (jogo.getWindow().isOpen())
    {
        jogo.update();
        jogo.render();
    }
    
    return 0;
}