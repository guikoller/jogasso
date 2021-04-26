#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Tile{
public:
    sf::Sprite sprite;
    sf::Vector2f pos;
    bool dano;

    Tile(sf::Texture& texture, sf::IntRect texture_rect,float x, float y, bool dano);
    Tile();
    ~Tile();
    void initTextura();
    const sf::FloatRect getGlobalBounds()const;
    void update();
    void render(sf::RenderTarget&target);
};