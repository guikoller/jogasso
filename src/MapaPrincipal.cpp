#include "MapaPrincipal.h"


MapaPrincipal::MapaPrincipal(/* args */){
    initVariaveis();
	initTextura();
	desenhaMapa();
}

MapaPrincipal::~MapaPrincipal(){
}


void MapaPrincipal::desenhaMapa(){
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
			
			if (i == 0 && j == 0)//canto superior esquerdo
			{
				Linha.push_back(new Tile(this->textura, canto_s_e, i * 64, j * 64,false, true));
			}
			else if (i == 0 && (j+1) == this->altura)//canto inferior esquerdo
			{
				Linha.push_back(new Tile(this->textura, canto_i_e, i * 64, j * 64,false, true));
			}
			else if (j == 0 && (i+1) ==this->largura)//canto inferior esquerdo
			{
				Linha.push_back(new Tile(this->textura, canto_s_d, i * 64, j * 64,false, true));
			}
			else if ((i+1) == this->largura && (j+1) == this->altura )//canto inferior direito
			{
				Linha.push_back(new Tile(this->textura, canto_i_d, i * 64, j * 64,false, true));
			}
			else if (i == 0)//parede esquerda
			{
				Linha.push_back(new Tile(this->textura, parede_esq, i * 64, j * 64,false, true));
			}
			else if (j== 0)//teto
			{
				Linha.push_back(new Tile(this->textura, teto, i * 64, j * 64,false, true));
			}
			else if (j+1 == this->altura)//chão
			{
				Linha.push_back(new Tile(this->textura, chao, i * 64, j * 64,false, true));
			}
			else if (i+1 == this->largura)//parede direita
			{
				Linha.push_back(new Tile(this->textura, parede_dir, i * 64, j * 64,false, true));
			}
			else if ((i > 0 && i < 20 && j == 10)|| (i > 5 && i < 25 && j == 5))//chão 2
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
