#include "LevelFinal.h"

void LevelFinal::initEntidade(){
    this->espadachim = new Espadachim();
    this->mapa = new MapaPrincipal();

    this->espadachim->hitBox.setPosition(sf::Vector2f(200.f,200.f));
}

LevelFinal::LevelFinal(sf::RenderWindow *window, std::stack<State*>* states):LevelBase(window, states){
    initEntidade();
    iniciaBotao();
}

LevelFinal::~LevelFinal(){
    delete this->espadachim;
    delete this->mapa;
    //destrutor bottões
    destroiBotao();
}

void LevelFinal::updateColisao(){
    
    sf::FloatRect nextPos;
    
    for (int i = 0; i < this->mapa->getLargura(); i++)
    {
        for (int j = 0; j < this->mapa->getAltura(); j++)
        {
            sf::FloatRect playerBounds = espadachim->getGlobalBounds();
            sf::FloatRect tileBounds = this->mapa->getSprite(i,j).getGlobalBounds();
            
            nextPos = playerBounds;
            nextPos.left += this->espadachim->velocidade.x;
            nextPos.top += this->espadachim->velocidade.y;
            


            // (x, y)-----------------------(x + width, y)
            // |                                         |
            // |                                         |
            // |                                         |
            // |                                         |
            // |                                         |
            // (x, y + height)-----(x + width, y + height)
           
            if (this->mapa->getSolido(i,j))
            {
                if (tileBounds.intersects(nextPos))
                {
                    //baixo
                    if (playerBounds.top < tileBounds.top
                        && playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height
                        && playerBounds.left < tileBounds.left + tileBounds.width
                        && playerBounds.left + playerBounds.width > tileBounds.left
                    )
                    {
                        this->espadachim->velocidade.y = 0.f;
                        this->espadachim->velocidade.x = 0.f;
                        this->espadachim->hitBox.setPosition(espadachim->hitBox.getPosition().x, tileBounds.top - playerBounds.height);
                        printf("colisão chão\n"); 
                    }
                    // cima
                    if (playerBounds.top > tileBounds.top
                        && playerBounds.top + playerBounds.height > tileBounds.top + tileBounds.height
                        && playerBounds.left < tileBounds.left + tileBounds.width
                        && playerBounds.left + playerBounds.width > tileBounds.left
                    )
                    {
                        this->espadachim->velocidade.y = 0.f;
                        this->espadachim->setPosicao(espadachim->hitBox.getPosition().x, tileBounds.top + tileBounds.height);
                        printf("colisão topo\n"); 
                    } 
                    //direita
                    else if (playerBounds.left < tileBounds.left
                        && playerBounds.left + playerBounds.width < tileBounds.left + tileBounds.width
                        && playerBounds.top < tileBounds.top + tileBounds.height
                        && playerBounds.top + playerBounds.height > tileBounds.top
                    )
                    {
                        this->espadachim->velocidade.x = 0.f;
                        this->espadachim->setPosicao(this->espadachim->getPosicao().x - playerBounds.width , playerBounds.top); 
                        printf("colisão direita\n"); 

                    }
                    //esquerda
                    else if (playerBounds.left > tileBounds.left
                        && playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width
                        && playerBounds.top < tileBounds.top + tileBounds.height
                        && playerBounds.top + playerBounds.height > tileBounds.top
                    )
                    {
                        this->espadachim->velocidade.x = 0.f;
                        this->espadachim->setPosicao(this->espadachim->getPosicao().x + playerBounds.width,this->espadachim->getPosicao().y);
                        printf("colisão esquerda\n"); 
                    }    
                }
                
            }            
        }
        
    }
}

void LevelFinal::updateEntidade(){
    this->espadachim->update();    
}


void LevelFinal::render(sf::RenderTarget&target){
    // printf("renderizado\n");
    this->mapa->render(target);
    this->espadachim->render(target);
    this->renderBotao(target);
}