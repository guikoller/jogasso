#pragma once
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>


class LevelBase{
protected:
    virtual void initEntidade() = 0;
public:
    LevelBase(/* args */);
    virtual ~LevelBase();

    //Functions
    virtual void updateColisao()=0;
    virtual void updateEntidade() = 0;
    void update();
    virtual void render(sf::RenderTarget&target)= 0;
};
