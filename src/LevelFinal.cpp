#include "LevelFinal.h"

void LevelFinal::initEntidade(){
    this->espadachim = new Espadachim();
    this->martelador = new Martelador();
    this->goblin = new Goblin();
    this->mapa = new MapaFinal();
    this->espinho = new Espinho;
    this->porta = new Porta;
    this->portal = new Portal;
    this->porta->sprite.setPosition(sf::Vector2f(200,720));
    this->portal->sprite.setPosition(sf::Vector2f(200,500));

    this->goblin->setPosicao(500, 490);
    this->goblin->setVelX(-1.f);
    this->espinho->sprite.setPosition(sf::Vector2f(1200, 760));
    this->espadachim->setPosicao(250,700);
    this->martelador->setPosicao(250,700);
    this->dt = 0;
}

void LevelFinal::initListaInimigo()
{
    this->monstro = new Monstro;
    this->esqueleto = new Esqueleto;
    this->listaInimigos->incluir(monstro);
    this->listaInimigos->incluir(esqueleto);
    this->monstro->setPosicao(600, 760);
    this->esqueleto->setPosicao(1000, 760);
}
LevelFinal::LevelFinal(sf::RenderWindow *window, std::stack<State*>* states):LevelBase(window, states){
    initEntidade();
    iniciaBotao();
    iniciaPlacar(0);
    iniciaVida();
}

LevelFinal::~LevelFinal(){
    delete this->espadachim;
    delete this->martelador;
    delete this->mapa;
    delete this->goblin;
    delete this->espinho;
    delete this->portal;
    delete this->porta;
    //destrutor bottões
    destroiBotao();
}

void LevelFinal::updateColisao(){
    
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
                if (this->mapa->getSolido(i,j))
            {
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
     //colisao obstaculos
    if(Collision::PixelPerfectTest(this->portal->sprite, this->espadachim->getSprite()))
    {
        //teleporta
        this->espadachim->velocidade.x = 0.f;
        this->espadachim->setPosicao(250, 700);
        printf("colidiu com portal\n");
    }
    if(Collision::PixelPerfectTest(this->espinho->sprite, this->espadachim->getSprite()))
    {
        this->espadachim->vida -= 1;
        this->espadachim->setPosicao(this->espadachim->getPosicao().x-20,this->espadachim->getPosicao().y-20);
                
        printf("colidiu com espinho\n");
    }
    if(segundoJogador)
    {
        if(Collision::PixelPerfectTest(this->portal->sprite, this->martelador->getSprite()))
        {
            //teleporta pro inicio da fase
            this->martelador->velocidade.x = 0.f;
            this->martelador->setPosicao(250, 700);
            printf("colidiu com portal\n");
        }
        if(Collision::PixelPerfectTest(this->espinho->sprite, this->martelador->getSprite()))
        {
            this->martelador->vida -= 1;
            this->martelador->setPosicao(this->espadachim->getPosicao().x-20,this->espadachim->getPosicao().y-20);
                
            printf("colidiu com espinho\n");
        }
    } 
    this->dt += 0.1;
    this->goblin->jogadorPerto(this->espadachim, &dt);

    if (Collision::PixelPerfectTest(this->goblin->getSprite(), this->martelador->getSprite()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
        {
            this->goblin->vida -= 2;
        }
        
    }
    if (Collision::PixelPerfectTest(this->goblin->getSprite(), this->espadachim->getSprite()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            this->goblin->vida -= 2;
        }
        
    }


}

void LevelFinal::updateEntidade(){
    this->espadachim->update();  
    if(segundoJogador)
        this->martelador->update();
    if (this->goblin->getVida()>0)
    {
        this->goblin->update(); 
    }
    
    if(this->goblin->getVida() <= 0){
        this->placar=10000;
    }
       
}


void LevelFinal::render(sf::RenderTarget&target){
    // printf("renderizado\n");
    this->mapa->render(target);

    if (this->goblin->getVida()>0){
       this->goblin->render(target);  
    } 

    this->porta->render(target);
    this->portal->render(target);
    this->espinho->render(target);

    if(segundoJogador)
        this->martelador->render(target);

    this->espadachim->render(target);
    this->renderPlacar(target);
    this->renderVida(target);
    this->renderBotao(target);
}