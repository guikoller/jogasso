#include "TileMap.h"

void TileMap::initVariaveis(){
	this->altura = 15;
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

TileMap::~TileMap(){}

void TileMap::initTiles(){
	this->mapa.clear();
	sf::IntRect intR = sf::IntRect(0,0, 32, 32);
	std::vector<Tile *> firstRow;
	firstRow.push_back(new Tile(this->textura, intR, 20, 20,false));

	mapa.push_back(firstRow);
}

void TileMap::render(sf::RenderTarget&target){
	for (int i = 0; i < this->altura; i++)
	{
		for (int j = 0; j < this->largura; j++)
		{
			if(!this->mapa.empty()){
				target.draw(this->mapa[i][j]->sprite);
				printf("tile desenhado");
			}
		}
		
	}
	
}