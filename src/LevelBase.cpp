#include "LevelBase.h"

void LevelBase::iniciaBotao(){
    this->isPaused = false;
    this->segundoJogador = false;

    this->btns["voltar"] = new Botao(600,200, 350,80, "Continuar", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));

    this->btns["jogador"] = new Botao(600,300, 350,80, "Adicionar Jogador", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));

    this->btns["salvarScore"] = new Botao(600,400, 350,80, "Salvar Pontuacao", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
    this->btns["SalvarJogo"] = new Botao(600,500, 350,80, "Salvar Jogo", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
    this->btns["CarregarJogo"] = new Botao(600,600, 350,80, "Carregar Jogo", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
    this->btns["SAIR"] = new Botao(600,700, 350,80, "Sair", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
}
void LevelBase::iniciaPlacar(int placar){
    bool write = true;
    this->placar = placar;
    this->textoPlacar.setFont(this->fonte);
    this->textoPlacar.setFillColor(sf::Color::White);
    this->textoPlacar.setCharacterSize(70);
    this->textoPlacar.setPosition(sf::Vector2f(1300.f, 30.f));
}
void LevelBase::iniciaVida(){
    this->textoVida.setFont(this->fonte);
    this->textoVida.setFillColor(sf::Color::White);
    this->textoVida.setCharacterSize(70);
    this->textoVida.setPosition(sf::Vector2f(200.f, 30.f));
}

LevelBase::LevelBase(sf::RenderWindow *window, std::stack<State*>* states):State(window, states){
}

LevelBase::~LevelBase(){}

void LevelBase::destroiBotao(){
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it!= this->btns.end(); ++it)
    { 
        delete it->second;
    }
}

void LevelBase::updateBotao(){
    for (auto &it : this->btns){
        it.second->update(this->mousePosView);
    }

    // SAIR DO JOGO
    if (this->btns["SAIR"]->isPressed()){
        this->quit = true;
    }else if (this->btns["voltar"]->isPressed()){
        this->isPaused = false;
    }else if (this->btns["jogador"]->isPressed()){
        this->segundoJogador = true;
    }else if (this->btns["salvarScore"]->isPressed()){
       //salvar pontuação 
       salvarPlacar();
    }else if (this->btns["SalvarJogo"]->isPressed()){
        // salvar jogo
    }else if (this->btns["CarregarJogo"]->isPressed()){
        //carregar jogo
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->isPaused = true;
        this->write = true;
    }
}

void LevelBase::updateVida(){
    int vida  = this->espadachim->vida;
    this->textoVida.setString(std::to_string(vida));
    if (vida<=0){
        this->quit = true;
    }    
}

void LevelBase::updatePlacar(){
    this->textoPlacar.setString(std::to_string(this->placar));
}

void LevelBase::update(){
    if (!isPaused){
        this->updateEntidade();
        this->updateColisao();
    }
    this->updateKeybinds();
    this->updateMousePosition();
    this->updateBotao();
    this->updatePlacar();
    this->updateVida();
}

void LevelBase::renderBotao(sf::RenderTarget &target){
    if (this->isPaused){
        for (auto &it : this->btns){
        it.second->render(target);
        } 
    }
}

void LevelBase::renderPlacar(sf::RenderTarget &target){
    target.draw(this->textoPlacar);
}
void LevelBase::renderVida(sf::RenderTarget &target){
    target.draw(this->textoVida);
}

void LevelBase::salvarPlacar(){
    if(write){
        arquivoPlacar.open("Placar/placar.txt", std::ios::app);
        arquivoPlacar<<placar<<"\n";
        arquivoPlacar.close();
        this->write = false;
    }    
}