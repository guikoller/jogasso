#include "SFML/Graphics.hpp"
#include <math.h>



/*
Classe criada para gerenciar e executar colisoes e seus
efeitos como a perca de vida e impossibilidade de atravessar paredes
*/

class Fase;
class Jogador;
class Inimigo;
class GerenciadorColisoes{
    private:
    //Efeitos das colisoes
    void paredeJogador(){

    }
    public:
    GerenciadorColisoes(){}
    ~GerenciadorColisoes(){}
    //Checagem
    /*
    bool checarColisao(Jogador *p1, Jogador *p2){

    }
    bool checarColisao(Jogador *p1, Inimigo *p2){
        
    }
    */
    bool checarColisao(Jogador *p1, Fase *p2){
        /*
        Se naquela posicao há um bloco colidível, essa funcao impede que o personagem ande em direcao ao bloco,
        ou seja, impede que entre no bloco
        */
    }
    /*
    bool checarColisao(Inimigo *p1, Inimigo *p2){
        
    }
    bool checarColisao(Inimigo *p1, Fase *p2){
        
    }
    */
    float distanciaEoclidiana(sf::Vector2f& v1,sf::Vector2f& v2){
        return sqrt(pow(v1.x - v2.x,2) + pow(v1.y - v2.y,2));
    }
    



};