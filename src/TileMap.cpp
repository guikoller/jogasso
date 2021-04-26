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
	firstRow.push_back(new Tile(this->textura, intR, 50, 50,false));
	firstRow.push_back(new Tile(this->textura, intR, 80, 80,false));
	firstRow.push_back(new Tile(this->textura, intR, 110, 110,false));
	firstRow.push_back(new Tile(this->textura, intR, 140, 140,false));

	mapa.push_back(firstRow);
}

void TileMap::render(sf::RenderTarget&target){
	// for (int i = 0; i < this->altura; i++)
	// {
	// 	for (int j = 0; j < this->largura; j++)
	// 	{
	// 		printf("%d %d\n",i ,j);
	// 		if(!this->mapa[i].empty()){
	// 			target.draw(this->mapa[i][j]->sprite);
	// 			printf("tile desenhado");
	// 		}
	// 	}
		
	// }
	target.draw(this->mapa[0][0]->sprite);
	target.draw(this->mapa[0][1]->sprite);
	target.draw(this->mapa[0][2]->sprite);
	target.draw(this->mapa[0][3]->sprite);
	target.draw(this->mapa[0][4]->sprite);

	
	
}