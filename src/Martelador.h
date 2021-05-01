#include "Jogavel.h"

namespace Personagem{
    namespace Jogavel{
        class Martelador: protected Jogavel{
        private:
            void iniciaVariaveis();
            void iniciaTextura();
            void iniciaSprite();
        public:
            Martelador(/* args */);
            ~Martelador();
            virtual void move(const float x, const float y);
            virtual void upadateMovimento();
            virtual void uptadeAnimacao();
        };
    }
}
