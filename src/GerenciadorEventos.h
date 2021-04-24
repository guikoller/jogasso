class Personagem;
class Inimigo;
class GerenciadorGrafico;

class GerenciadorEventos{
    private:
        GerenciadorGrafico *p;
    public:
        GerenciadorEventos();
        ~GerenciadorEventos();
        void iniciar(void);
        void carregarJogo(int id);
        void startPlay();
        //Colisao personagem inimigo
        void checacolisaoI();
        //Colisao personagem fase
        void checacolisaoF();
        //Colisao inimigo fase
        void checacolisaoIF();
        void iniciarJogo(void);
        void sair(void);
};