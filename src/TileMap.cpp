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
	sf::IntRect tijolo = sf::IntRect(32,256, 32, 32);
	std::vector<Tile *> Linha;

	
	// for (int i = 0; i < this->altura; i++)
	// {
	// 	Linha1.push_back(new Tile(this->textura, tijolo, 0, i * 64,false));
	// }

	for (int i = 0; i < this->largura; i++)
	{
		for (int j = 0; j < this->altura; j++)
		{
			Linha.push_back(new Tile(this->textura, tijolo, i * 64, j * 64,false, false));
			
		}
		this->mapa.push_back(Linha);
		Linha.clear();
	}
	
	

	// mapa.push_back(Linha1);
}

void TileMap::render(sf::RenderTarget&target){
	for (int i = 0; i < this->largura; i++)
	{
		for (int j = 0; j < this->altura; j++)
		{
			target.draw(this->mapa[i][j]->sprite);
		}
		
		
		
	}
	
	// target.draw(this->mapa[0][1]->sprite);
	// target.draw(this->mapa[0][2]->sprite);
	// target.draw(this->mapa[0][3]->sprite);
	// target.draw(this->mapa[0][4]->sprite);

	
	
}