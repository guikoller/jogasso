class Personagem;
class Inimigo;
class GerenciadorColisoes;

class GerenciadorEventos{
    private:
        GerenciadorColisoes *p;
    public:
        GerenciadorEventos();
        ~GerenciadorEventos();
        void iniciar(void);
        void carregarJogo();
        void startPlay();
        /*
        //Colisao personagem inimigo
        void checacolisaoI();
        //Colisao personagem fase
        void checacolisaoF();
        //Colisao inimigo fase
        */
        //sf::Keyboard botaoTecladoPressionado(void){return sf::Keyboard::isKeyPressed;}
        void iniciarJogo(void);
        void sair(void);
};