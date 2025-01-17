#include "Pontuacao.h"

void Pontuacao::iniciaBotao(){
    this->btns["SAIR"] = new Botao(300,750, 200,80, "Sair", &this->fonte,
        sf::Color(0,0,0,230), 
        sf::Color(10,10,10,200), 
        sf::Color(20,20,20,150));
}

void Pontuacao::iniciaBackground(){
    if (!this->texture.loadFromFile("Textures/Background/bg.png"))
        printf("BACKGROUND NÃO CARREGADO\n");
    
    this->background.setTexture(this->texture);
    this->background.setScale(6.f,7.f);
}


void Pontuacao::iniciaTitulo(){
    this->titulo.setFont(this->fonte);
    this->titulo.setString("Placares:");
    this->titulo.setCharacterSize(100);
    this->titulo.setColor(sf::Color(250,250,250,250));
    this->titulo.setPosition(sf::Vector2f(100,50));
}

Pontuacao::Pontuacao(sf::RenderWindow *window, std::stack<State*>* states):State(window, states){    
    iniciaTitulo();
    iniciaBackground();
    iniciaBotao();
    iniciaPlacar();
}

void Pontuacao::iniciaPlacar(){
    std::string texto = readFile();

    this->placar.setFont(this->fonte);
    this->placar.setString(texto);
    this->placar.setFillColor(sf::Color::White);
    this->placar.setCharacterSize(45);
    this->placar.setPosition(sf::Vector2f(800,50));
}

Pontuacao::~Pontuacao()
{
    auto it = this->btns.begin();

    for (it = this->btns.begin(); it!= this->btns.end(); ++it)
    { 
        delete it->second;
    }

}

void Pontuacao::updateBotao(){
    for (auto &it : this->btns)
    {
        it.second->update(this->mousePosView);
    }
    // SAIR DO JOGO
    if (this->btns["SAIR"]->isPressed()){
        this->quit = true;
    }   

}

void Pontuacao::update(){
    this->updateKeybinds();
    this->updateMousePosition();
    // std::cout<<this->mousePosWindow.x <<", "<< this->mousePosWindow.y << std::endl;
    updateBotao();
}

void Pontuacao::renderBotao(sf::RenderTarget &target){
    for (auto &it : this->btns)
    {
        it.second->render(target);
    } 
}

void Pontuacao::render(sf::RenderTarget &target){
    target.draw(this->background);
    renderBotao(target);
    target.draw(this->titulo);
    target.draw(this->placar);
}

std::string Pontuacao::readFile(){
    std::ifstream inFile;
    inFile.open("Placar/placar.txt"); //open the input file

    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file

    std::cout << str << "\n"; //you can do anything with the string!!!
    return str;
}

