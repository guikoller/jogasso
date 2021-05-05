#pragma once
#include <SFML/Graphics.hpp>

class Colisor{
private:
    sf::RectangleShape body;
public:
    Colisor(sf::RectangleShape &body);
    ~Colisor();

    void Move(float dx, float dy);
    bool checaColisao(Colisor *other, float push);
    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();
};
