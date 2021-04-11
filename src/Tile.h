#include "Jogo.h"

class Tile{
private:
    sf::Sprite sprite;
    const bool dano;
public:
    Tile(sf::Texture& texture, sf::IntRect texture_rect, bool dano = false);
    ~Tile();
    const sf::FloatRect getGlobalBounds()const;
    void update();
    void render(sf::RenderTarget&target);
};