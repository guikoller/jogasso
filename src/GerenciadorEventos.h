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
        void checacolisao();
        //Colisao personagem fase
        void checacolisao();
        //Colisao inimigo fase
        void checacolisao();
        void iniciarJogo(void);
        void sair(void);
};