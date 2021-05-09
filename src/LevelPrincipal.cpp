#include "LevelPrincipal.h"

void LevelPrincipal::initEntidade(){
    this->espadachim = new Espadachim();
    
    this->monstro = new Monstro();
    this->esqueleto = new Esqueleto();
    
    this->mapa = new MapaPrincipal();
    this->listaInimigos = new Lista<Inimigo>;
    this->listaEsqueletos = new Lista<Esqueleto>;
    
    this->espadachim->hitBox.setPosition(sf::Vector2f(200.f,200.f));
    
    this->monstro->setPosicao(1000,925);
    this->esqueleto->setPosicao(rand()%1405+70, 595);

}
// 1475 = limite direito do mapa, 70 = limite direito do mapa 
// 400 = limite esquerdo da plataforma de cima, 280 = altura plataforma de cima
// 1220 = limite direito da plataforma do meio, 595 = altura da plataforma do meio
// 925 = altura do chão de baixo
void LevelPrincipal::initListaInimigo()
{
    for(int i = 0; i < 1; i++)
    {
        Inimigo *m1 = new Monstro;
        Inimigo *e1 = new Esqueleto;
        this->listaInimigos->incluir(m1);
        this->listaInimigos->incluir(e1);
        m1->setPosicao(rand()%1405+70, 595); 
        e1->setPosicao(rand()%1405+70, 595); 
        m1->setPosInicial(m1->hitBox.getPosition().x);
        e1->setPosInicial(e1->hitBox.getPosition().x);
    }


}
LevelPrincipal::LevelPrincipal(sf::RenderWindow *window, std::stack<State*>* states):LevelBase(window, states){
    initEntidade();
    initListaInimigo();
    iniciaBotao();
}

LevelPrincipal::~LevelPrincipal(){
    delete this->espadachim;
    delete this->monstro;
    delete this->esqueleto;
    delete this->mapa;


    //destrutor bottões
    destroiBotao();
}

void LevelPrincipal::updateColisao(){
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
                        && playerBounds.top + playerBounds.height > tileBounds.top + 40
                    )
                    {
                        this->espadachim->velocidade.x = 0.f;
                        this->espadachim->setPosicao(this->espadachim->getPosicao().x - playerBounds.width + 30, playerBounds.top); 
                        printf("colisão direita\n"); 

                    }
                    //esquerda
                    else if (playerBounds.left > tileBounds.left
                        && playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width
                        && playerBounds.top < tileBounds.top + tileBounds.height
                        && playerBounds.top + playerBounds.height > tileBounds.top + 40
                    )
                    {
                        this->espadachim->velocidade.x = 0.f;
                        this->espadachim->setPosicao(this->espadachim->getPosicao().x + playerBounds.width - 30,this->espadachim->getPosicao().y);
                        printf("colisão esquerda\n"); 
                    }    
                }
                
            }            
        }
        
    }
}



void LevelPrincipal::updateEntidade(){
    this->espadachim->update();  
    //this->esqueleto->update(); 
    //this->monstro->update();
    for(int i = 0; i < this->listaInimigos->getLen(); i++)
    {
        Inimigo* temp = this->listaInimigos->getItem(i);
        temp->update();
    }
}



void LevelPrincipal::render(sf::RenderTarget&target){
    // printf("renderizado\n");
    this->mapa->render(target);
    this->espadachim->render(target);
    //this->monstro->render(target);
    //this->esqueleto->render(target);
    for(int i = 0; i < listaInimigos->getLen(); i++)
    {
        Inimigo* temp = listaInimigos->getItem(i);
        temp->render(target);
    }
    
    this->renderBotao(target);
}