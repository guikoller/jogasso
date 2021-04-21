#include "Entidade.h"
#include "Animacao.h"

class Player: public Entity{
public:
	enum {stay,walk,jump} STATE;
	int cash;
	float sx, sy;
	std::map<std::string,bool> key;//teclado
	
	Player(AnimationManager &a, int x, int y);
	void Keyboard();
	void Animation(float time);
	void update(float time);
	void Collision(int num);
};