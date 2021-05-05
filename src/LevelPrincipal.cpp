#include "LevelPrincipal.h"

void LevelPrincipal::initEntidade(){
    Espadachim espadachim();
    this->mapa = new MapaPrincipal();

    this->espadachim->hitBox.setPosition(sf::Vector2f(200.f,200.f));
}

LevelPrincipal::LevelPrincipal(){
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
            if (this->mapa->getSolido(i,j)){
               mapa->getColisao(i,j).checaColisao(this->espadachim->getColisao(),0.0f); 
                    
                
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