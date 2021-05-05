#include "Colisor.h"

Colisor::Colisor(sf::RectangleShape &body):body(body){
}

Colisor::~Colisor(){
}

void Colisor::Move(float dx, float dy){ 
    this->body.move(dx,dy);
}

sf::Vector2f Colisor::getPosition(){
    return this->body.getPosition();
}

sf::Vector2f Colisor::getHalfSize(){
    return this->body.getSize() / 2.0f;
}


bool Colisor::checaColisao(Colisor *o, float push){
    Colisor *other = o;

    sf::Vector2f otherPosition = other->getPosition();
    sf::Vector2f otherHalfSize = other->getHalfSize();

    sf::Vector2f thisPosition = other->getPosition();
    sf::Vector2f thisHalfSize = other->getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    
    float intersectX = abs(deltaX) - (otherHalfSize.x - thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y - thisHalfSize.y);

    if (intersectX <  0.0f && intersectY <  0.0f){
        push  = std::min(std::max(push, 0.0f), 1.0f);//clamping
        
        if (intersectX > intersectY){
            if (deltaX > 0.0f){
                this->Move(intersectX * (1.0f - push),0.0f);
                other->Move(-intersectX * push, 0.0f);
            }else{
                this->Move(-intersectX * (1.0f - push),0.0f);
                other->Move(intersectX * push, 0.0f);
            }
        }else{
            if (deltaY > 0.0f){
                this->Move(0.0f, intersectY * (1.0f - push));
                other->Move(0.0f, -intersectY * push);
            }else{
                this->Move(0.0f, -intersectY * (1.0f - push));
                other->Move(0.0f, intersectY * push);
            }
        }
        return true;
    }
    
    return false;
}