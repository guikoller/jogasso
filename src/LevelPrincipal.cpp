#include "LevelPrincipal.h"

void LevelPrincipal::initEntidade(){

    this->espadachim = new Espadachim();
    this->martelador = new Martelador();

    this->porta = new Porta();
    this->porta->sprite.setPosition(sf::Vector2f(1400,210));

    for (int i = 0; i < 5; i++)
    {
        this->caixa[i]  = new Caixa();
        this->espinho[i] = new Espinho();
    }
    
    this->caixa[1]->sprite.setPosition(sf::Vector2f(rand()%1075+400,280));
    this->caixa[2]->sprite.setPosition(sf::Vector2f(rand()%1075+400,280));
    this->caixa[3]->sprite.setPosition(sf::Vector2f(rand()%1150+70,595));
    this->caixa[4]->sprite.setPosition(sf::Vector2f(rand()%1150+70,595));
    this->caixa[0]->sprite.setPosition(sf::Vector2f(1450,925));

    this->espinho[1]->sprite.setPosition(sf::Vector2f(1200,210));
    this->espinho[2]->sprite.setPosition(sf::Vector2f(1000,210));
    this->espinho[3]->sprite.setPosition(sf::Vector2f(1400,400));
    this->espinho[4]->sprite.setPosition(sf::Vector2f(1200,400));
    this->espinho[0]->sprite.setPosition(sf::Vector2f(200,900));
    
    this->mapa = new MapaPrincipal();
    this->listaInimigos = new Lista<Inimigo>;
    
    this->espadachim->setPosicao(200,900);
    this->martelador->setPosicao(200,900);

}
// 1475 = limite direito do mapa, 70 = limite esquerdo do mapa 
// 400 = limite esquerdo da plataforma de cima, 280 = altura plataforma de cima
// 1220 = limite direito da plataforma do meio, 595 = altura da plataforma do meio
// 925 = altura do chão de baixo


void LevelPrincipal::initListaInimigo()
{
    float vetorPosY[] = {280, 595, 925, 280, 595, 925};
    for(int i = 0; i < 6; i++)
    {
        this->monstro = new Monstro;
        this->esqueleto = new Esqueleto;
        this->listaInimigos->incluir(monstro);
        this->listaInimigos->incluir(esqueleto);
        if(vetorPosY[i] == 280)
        {
            monstro->setPosicao(rand()%1075+400, 280);
            esqueleto->setPosicao(rand()%1075+400, 280);
        }
        else if(vetorPosY[i] == 595)
        {
            monstro->setPosicao(rand()%1150+70, 595);
            esqueleto->setPosicao(rand()%1150+70, 595);
        }
        else
        {
            monstro->setPosicao(rand()%1405+70, 925);
            esqueleto->setPosicao(rand()%1405+70, 925);
        }
        if(i%2)
        {
            esqueleto->setVelX(rand()%4+2);
            monstro->setVelX(-rand()%4+2);
        }
        else
        {
            esqueleto->setVelX(-rand()%4+2);
            monstro->setVelX(rand()%4+2);
        }
    }
}
LevelPrincipal::LevelPrincipal(sf::RenderWindow *window, std::stack<State*>* states):LevelBase(window, states){
    initEntidade();
    initListaInimigo();
    iniciaBotao();
    iniciaPlacar();
}

LevelPrincipal::~LevelPrincipal(){
    delete this->espadachim;
    delete this->martelador;
    delete this->monstro;
    delete this->esqueleto;
    delete this->mapa;

    for (int i = 0; i < 5; i++){
        delete this->caixa[i];
        delete this->espinho[i];
    }
    for(int i = 0; i < listaInimigos->getLen(); i++)
    {
        Inimigo *aux = listaInimigos->getItem(i);
        listaInimigos->excluir(aux);
    }
    //destrutor bottões
    destroiBotao();
}

void LevelPrincipal::updateColisao(){
    sf::FloatRect nextPos;
    sf::FloatRect nextPos2;
    for (int i = 0; i < this->mapa->getLargura(); i++)
    {
        for (int j = 0; j < this->mapa->getAltura(); j++)
        {
            //espadachim
            sf::FloatRect playerBounds = espadachim->getGlobalBounds();
            sf::FloatRect tileBounds = this->mapa->getSprite(i,j).getGlobalBounds();
            nextPos = playerBounds;
            nextPos.left += this->espadachim->velocidade.x;
            nextPos.top += this->espadachim->velocidade.y;
            //martelador
            sf::FloatRect player2Bounds = martelador->getGlobalBounds();
            nextPos2 = player2Bounds;
            nextPos2.left += this->martelador->velocidade.x;
            nextPos2.top += this->martelador->velocidade.y;
            //jogador padrão
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
            //segundo jogador
            if(segundoJogador){
                if (this->mapa->getSolido(i,j)){
                if (tileBounds.intersects(nextPos2))
                {
                    //baixo
                    if (player2Bounds.top < tileBounds.top
                        && player2Bounds.top + player2Bounds.height < tileBounds.top + tileBounds.height
                        && player2Bounds.left < tileBounds.left + tileBounds.width
                        && player2Bounds.left + player2Bounds.width > tileBounds.left
                    )
                    {
                        this->martelador->velocidade.y = 0.f;
                        this->martelador->velocidade.x = 0.f;
                        this->martelador->hitBox.setPosition(martelador->hitBox.getPosition().x, tileBounds.top - player2Bounds.height);
                        printf("colisão chão\n"); 
                    }
                    // cima
                    if (player2Bounds.top > tileBounds.top
                        && player2Bounds.top + player2Bounds.height > tileBounds.top + tileBounds.height
                        && player2Bounds.left < tileBounds.left + tileBounds.width
                        && player2Bounds.left + player2Bounds.width > tileBounds.left
                    )
                    {
                         this->martelador->velocidade.y = 0.f;
                        this->martelador->setPosicao(martelador->hitBox.getPosition().x, tileBounds.top + tileBounds.height);
                        printf("colisão topo\n"); 
                    } 
                    //direita
                    else if (player2Bounds.left < tileBounds.left
                        && player2Bounds.left + player2Bounds.width < tileBounds.left + tileBounds.width
                        && player2Bounds.top < tileBounds.top + tileBounds.height
                        && player2Bounds.top + player2Bounds.height > tileBounds.top + 40
                    )
                    {
                        this->martelador->velocidade.x = 0.f;
                        this->martelador->setPosicao(this->martelador->getPosicao().x - player2Bounds.width + 30, player2Bounds.top); 
                        printf("colisão direita\n"); 

                    }
                    //esquerda
                    else if (player2Bounds.left > tileBounds.left
                        && player2Bounds.left + player2Bounds.width > tileBounds.left + tileBounds.width
                        && player2Bounds.top < tileBounds.top + tileBounds.height
                        && player2Bounds.top + player2Bounds.height > tileBounds.top + 40
                    )
                    {
                        this->martelador->velocidade.x = 0.f;
                        this->martelador->setPosicao(this->martelador->getPosicao().x + player2Bounds.width - 30,this->martelador->getPosicao().y);
                        printf("colisão esquerda\n"); 
                    }    
                }                
            } 
            }           
        }
        
    }
    // colisoes obstaculos
    for(int i = 0; i < 5; i++)
    {
        if(Collision::PixelPerfectTest(this->espinho[i]->sprite, this->espadachim->getSprite()))
        {
            //perde vida
            printf("colidiu com espinho\n");
        }
        if(Collision::PixelPerfectTest(this->caixa[i]->sprite, this->espadachim->getSprite()))
        {
            this->espadachim->velocidade.x = 0.f;
            this->espadachim->setPosicao(this->espadachim->getPosicao().x, this->espadachim->getPosicao().y - this->espadachim->getGlobalBounds().height + 35);
            printf("colidiu com caixa\n");
        }
        if(segundoJogador)
        {
            if(Collision::PixelPerfectTest(this->espinho[i]->sprite, this->martelador->getSprite()))
            {
                //perde vida
                printf("colidiu com espinho\n");
            }
            if(Collision::PixelPerfectTest(this->caixa[i]->sprite, this->martelador->getSprite()))
            {
                this->martelador->velocidade.x = 0.f;
                this->martelador->setPosicao(this->martelador->getPosicao().x, this->martelador->getPosicao().y - this->martelador->getGlobalBounds().height + 35);
                printf("colidiu com caixa\n");
            }
        }
    }
    // colisoes inimigos
    for(int i = 0; i < listaInimigos->getLen(); i++)
    {
        Inimigo* aux = listaInimigos->getItem(i);
        if(Collision::PixelPerfectTest(aux->getSprite(), this->espadachim->getSprite()) && 
            this->espadachim->hitBox.getPosition().x < aux->hitBox.getPosition().x)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                listaInimigos->excluir(aux);
                printf("inimigo morto");
                this->placar += 100;
            }
            //perde vida
            this->espadachim->setPosicao(this->espadachim->getPosicao().x - this->espadachim->getGlobalBounds().width + 20, this->espadachim->getPosicao().y);
            printf("colidiu com inimigo\n");
        }
        else if(Collision::PixelPerfectTest(aux->getSprite(), this->espadachim->getSprite()) && 
            this->espadachim->hitBox.getPosition().x > aux->hitBox.getPosition().x)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                listaInimigos->excluir(aux);
                printf("inimigo morto");
                this->placar += 100;
            }
            //perde vida
            this->espadachim->setPosicao(this->espadachim->getPosicao().x + this->espadachim->getGlobalBounds().width - 20, this->espadachim->getPosicao().y);
        }
        if(segundoJogador)
        {
            if(Collision::PixelPerfectTest(aux->getSprite(), this->martelador->getSprite()) && 
                this->martelador->hitBox.getPosition().x < aux->hitBox.getPosition().x)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                {
                    listaInimigos->excluir(aux);
                    printf("inimigo morto");
                    this->placar += 100;
                }
                // perde vida
                this->martelador->setPosicao(this->martelador->getPosicao().x - this->martelador->getGlobalBounds().width + 20, this->martelador->getPosicao().y);
                printf("colidiu com inimigo\n");
            }
            else if(Collision::PixelPerfectTest(aux->getSprite(), this->martelador->getSprite()) && 
                    this->martelador->hitBox.getPosition().x > aux->hitBox.getPosition().x)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                {
                    listaInimigos->excluir(aux);
                    printf("inimigo morto");
                    this->placar += 100;
                }
                // perde vida
                this->martelador->setPosicao(this->martelador->getPosicao().x + this->martelador->getGlobalBounds().width - 20, this->martelador->getPosicao().y);
            }
        }
    }
    if(Collision::PixelPerfectTest(this->porta->sprite, this->espadachim->getSprite()))
        this->quit = true;
}



void LevelPrincipal::updateEntidade(){
    this->espadachim->update();  

    if(segundoJogador)
        this->martelador->update();

    for(int i = 0; i < this->listaInimigos->getLen(); i++)
    {
        Inimigo* temp = this->listaInimigos->getItem(i);
        temp->update();
    }
}



void LevelPrincipal::render(sf::RenderTarget&target){
    // printf("renderizado\n");
    this->mapa->render(target);

    this->porta->render(target);

    for (int i = 0; i < 5; i++)
    {
        this->caixa[i]->render(target);
        this->espinho[i]->render(target);
    }
    
    //this->monstro->render(target);
    //this->esqueleto->render(target);
    for(int i = 0; i < listaInimigos->getLen(); i++)
    {
        Inimigo* temp = listaInimigos->getItem(i);
        temp->render(target);
    }
    
    if(segundoJogador)
        this->martelador->render(target);

    this->espadachim->render(target);
    
    this->renderPlacar(target);
    this->renderBotao(target);
}