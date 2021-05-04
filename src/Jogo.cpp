#include "Jogo.h"
#include "Collision.h"


void Jogo::initWindow(){
    this->window.create(sf::VideoMode(1600,1010),"Jogasso", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(144);
    this->window.setVerticalSyncEnabled(true);
}

void Jogo::initEntidade(){
    this->martelador  = new Martelador();
    this->martelador->hitBox.setPosition(sf::Vector2f(200.f,200.f));
    this->monstro = new Monstro();
    this->mapa = new MapaPrincipal();
    this->monstro->move(100,0);
}


Jogo::Jogo(){
    this->initWindow();
    this->initEntidade();
}

Jogo::~Jogo(){
    delete this->martelador;
    delete this->monstro;
    delete this->mapa;
}

/////////////////////////////////////////////////////
//UPDATES////////////////////////////////////////////
/////////////////////////////////////////////////////
void Jogo::updateDT(){
    this->dt = this->dtClock.restart().asSeconds();
}


void Jogo::updateEntidade(){
    this->martelador->update();
    this->monstro->update();
}


void Jogo::updateColisao(){

    if(this->monstro->getGlobalBounds().top + this->monstro->getGlobalBounds().height > this->window.getSize().y){
        this->monstro->resetVelY();
        this->monstro->setPosicao(this->monstro->getGlobalBounds().left,
            this->window.getSize().y - this->monstro->getGlobalBounds().height
        );
    }
    
    

    


    sf::FloatRect nextPos;

    for (int i = 0; i < this->mapa->getLargura(); i++)
    {
        for (int j = 0; j < this->mapa->getAltura(); j++)
        {
            sf::FloatRect playerBounds = martelador->getGlobalBounds();
            sf::FloatRect tileBounds = this->mapa->getSprite(i,j).getGlobalBounds();
            
            nextPos = playerBounds;
            nextPos.left += this->martelador->velocidade.x;
            nextPos.top += this->martelador->velocidade.y;
            


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
                        this->martelador->velocidade.y = 0.f;
                        this->martelador->velocidade.x = 0.f;
                        this->martelador->hitBox.setPosition(martelador->hitBox.getPosition().x, tileBounds.top - playerBounds.height);
                        printf("colisão chão\n"); 
                    }
                    // cima
                    else if (playerBounds.top > tileBounds.top
                        && playerBounds.top + playerBounds.height > tileBounds.top + tileBounds.height
                        && playerBounds.left < tileBounds.left + tileBounds.width
                        && playerBounds.left + playerBounds.width > tileBounds.left
                    )
                    {
                        this->martelador->velocidade.y = 0.f;
                        // this->martelador->setPosicao(martelador->hitBox.getPosition().x, tileBounds.top + tileBounds.height + 20);
                        printf("colisão topo\n"); 
                    } 
                    //direita
                    else if (playerBounds.left < tileBounds.left
                        && playerBounds.left + playerBounds.width < tileBounds.left + tileBounds.width
                        && playerBounds.top < tileBounds.top + tileBounds.height
                        && playerBounds.top + playerBounds.height > tileBounds.top
                    )
                    {
                        this->martelador->velocidade.x = 0.f;
                        // this->martelador->setPosicao(this->martelador->getPosicao().x+ playerBounds.width, playerBounds.top); 
                        printf("colisão direita\n"); 

                    }
                    //esquerda
                    else if (playerBounds.left > tileBounds.left
                        && playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width
                        && playerBounds.top < tileBounds.top + tileBounds.height
                        && playerBounds.top + playerBounds.height > tileBounds.top
                    )
                    {
                        this->martelador->velocidade.x = 0.f;
                        // this->martelador->setPosicao(this->martelador->getPosicao().x,this->martelador->getPosicao().y);
                        printf("colisão esquerda\n"); 
                    }    
                }
                
            }            
        }
        
    }
    
    
        
}
void Jogo::updateSFMLevents(){
    //pega todos o eventos da janela
    while (this->window.pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)//se a janela for fechada
            this->window.close();
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
            this->window.close();// checa se uma tecla foi precionada e se foi, se é esc                   
    }
}

void Jogo::update(){
    this->updateSFMLevents();
    this->updateDT();
    this->updateColisao();
    this->updateEntidade();
    std::cout<<this->martelador->velocidade.x;
    std::cout<<"\n";
}
/////////////////////////////////////////////////////
//RENDER/////////////////////////////////////////////
/////////////////////////////////////////////////////
const sf::RenderWindow& Jogo::getWindow() const{//retorna estado da janela aberta ou fechada
    return this->window; 
}
void Jogo::render(){
    this->window.clear();
    //renderizão do jogo vai aqui

    this->renderEntidade();

    //
    this->window.display();
}
void Jogo::renderEntidade(){
    this->mapa->render(this->window);
    this->martelador->render(this->window);
    this->monstro->render(this->window);
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void Jogo::rodar(){
    while (this->getWindow().isOpen())
    {
        this->update();
        this->render();
    }
}