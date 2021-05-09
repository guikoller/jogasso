#include "MapaFinal.h"


MapaFinal::MapaFinal(/* args */){
    initVariaveis();
	initTextura();
	desenhaMapa();
}

MapaFinal::~MapaFinal(){
}


void MapaFinal::desenhaMapa(){
	this->mapa.clear();
	sf::IntRect tijolo = sf::IntRect(32,256, 32, 32);
	sf::IntRect parede_esq = sf::IntRect(64, 32, 32, 32);
	sf::IntRect parede_dir = sf::IntRect(0, 32, 32, 32);
	sf::IntRect teto = sf::IntRect(32, 64, 32, 32);
	sf::IntRect chao = sf::IntRect(32, 0, 32, 32);
	sf::IntRect canto_s_e = sf::IntRect(192, 0, 32, 32);
	sf::IntRect canto_s_d = sf::IntRect(224, 0, 32, 32);
	sf::IntRect canto_i_e = sf::IntRect(192, 32, 32, 32);
	sf::IntRect canto_i_d = sf::IntRect(224, 32, 32, 32);
	sf::IntRect chao2 = sf::IntRect(32, 128, 32, 32);
	
	std::vector<Tile *> Linha;

	
	// for (int i = 0; i < this->altura; i++)
	// {
	// 	Linha1.push_back(new Tile(this->textura, tijolo, 0, i * 64,false));
	// }



	for (int i = 0; i < this->largura; i++)
	{
		for (int j = 0; j < this->altura; j++)
		{
			
			if (i == 2 && j == 3)//canto superior esquerdo ok
			{
				Linha.push_back(new Tile(this->textura, canto_s_e, i * 64, j * 64,false, true));
			}
			else if (i == 2 && j == 13)//canto inferior esquerdo ok 
			{
				Linha.push_back(new Tile(this->textura, canto_i_e, i * 64, j * 64,false, true));
			}
			else if (i == 22 && j == 3)//canto inferior esquerdo
			{
				Linha.push_back(new Tile(this->textura, canto_s_d, i * 64, j * 64,false, true));
			}
			else if (i == 22 && j == 13)//canto inferior direito
			{
				Linha.push_back(new Tile(this->textura, canto_i_d, i * 64, j * 64,false, true));
			}
			else if (i == 2 && j >= 4 && j < 14)//parede esquerda
			{
				Linha.push_back(new Tile(this->textura, parede_esq, i * 64, j * 64,false, true));
			}
			else if (j==3 && i > 2 && i < 22)//teto
			{
				Linha.push_back(new Tile(this->textura, teto, i * 64, j * 64,false, true));
			}
			else if (j==13 && i > 2 && i < 22)//chão
			{
				Linha.push_back(new Tile(this->textura, chao, i * 64, j * 64,false, true));
			}
			else if (i == 22 && j >= 4 && j < 14)//parede direita
			{
				Linha.push_back(new Tile(this->textura, parede_dir, i * 64, j * 64,false, true));
			}
			else if (i > 2 && i < 19 && j == 10)//chão 2
			{
				Linha.push_back(new Tile(this->textura, chao2, i * 64, j * 64,false, true));
			}
			else //tijolo parede
			{
				Linha.push_back(new Tile(this->textura, tijolo, i * 64, j * 64,false, false));
			}			
			
					
		}
		this->mapa.push_back(Linha);
		Linha.clear();
	}

	// Linha.push_back(new Tile(this->textura, canto_s_d, 100, 100,false, true));
	// this->mapa.push_back(Linha);
	// Linha.clear();


}
