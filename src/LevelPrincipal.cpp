#include "LevelPrincipal.h"

void LevelPrincipal::initEntidade(){
    this->espadachim = new Espadachim();
    this->mapa = new MapaPrincipal();

    this->espadachim->hitBox.setPosition(sf::Vector2f(200.f,200.f));
}

LevelPrincipal::LevelPrincipal(sf::RenderWindow *window):State(window){
    initEntidade();
}

LevelPrincipal::~LevelPrincipal(){
    delete this->espadachim;
    delete this->mapa;
}

void LevelPrincipal::updateColisao(){
    for (int i = 0; i < this->mapa->getLargura(); i++)
    {
        for (int j = 0; j < this->mapa->getAltura(); j++)
        {
            if(Collision::PixelPerfectTest(this->espadachim->hitBox, this->mapa->getSprite(i,j)) && this->mapa->getSolido(i,j)){
                this->espadachim->resetVelY();
                this->espadachim->resetVelX();
                printf("COLIDIU\n");
            }   
        }
    }
}
void LevelPrincipal::updateEntidade(){
    this->espadachim->update();    
}

void LevelPrincipal::render(sf::RenderTarget&target){
    // printf("renderizado\n");
    this->mapa->render(target);
    this->espadachim->render(target);

}