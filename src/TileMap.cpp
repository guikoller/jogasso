#include "TileMap.h"

void TileMap::initVariaveis(){
	this->altura = 16;
	this->largura = 25;
}

void TileMap::initTextura(){
    if (!this->textura.loadFromFile("Textures/Tiles/Tileset.png")){
		printf("erro ao carregar tileset\n");
	}
}


TileMap::TileMap(/* args */){    
    initVariaveis();
	initTextura();
	initTiles();
}
int TileMap::getAltura(){
	return this->altura;
}
int TileMap::getLargura(){
	return this->largura;
}
sf::Sprite TileMap::getSprite(int x, int y){
	return this->mapa[x][y]->sprite;
}
bool TileMap::getSolido(int x, int y){
	return this->mapa[x][y]->solido;
}



TileMap::~TileMap(){
	for (int i = 0; i < this->largura; i++)
	{
		for (int j = 0; j < this->altura; j++)
		{
			delete mapa[i][j];
		}		
	}	
}

void TileMap::render(sf::RenderTarget&target){
	for (int i = 0; i < this->largura; i++)
	{
		for (int j = 0; j < this->altura; j++)
		{
			target.draw(this->mapa[i][j]->sprite);
		}
		
		
		
	}	
}