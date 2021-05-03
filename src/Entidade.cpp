#include "Entidade.h"

Entidade::Entidade(){}
Entidade::~Entidade(){}


void Entidade::render(sf::RenderTarget&target){
    target.draw(this->sprite);
}