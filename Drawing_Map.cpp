#include <SFML\Graphics.hpp>
#include <iostream>
#include "Drawing_Map.h"
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

Drawing_Map::Drawing_Map(string TileMap[])
{
	// sound effects
	COIN.loadFromFile("sound/coin.ogg");
	coin_sound.setBuffer(COIN);

TileMap[0]  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
TileMap[1]  = "a                                                                                                                                                                                                      a";
TileMap[2]  = "a                                                                                                                                                                                                      a";
TileMap[3]  = "a    A         A            A             A             A              A               A               A              A               A               A              A              A                  a";
TileMap[4]  = "a         A           A            A             A              A              A               A               A              A               A               A              A               A         a";
TileMap[5]  = "a              c c c c c c c c c              c c c c c c c c c            c c c c c c c c c         c c c c c c c c c                                                                                 a";
TileMap[6]  = "a               c c c c c c c c c              c c c c c c c c c            c c c c c c c c c         c c c c c c c c c                                                                                a";
TileMap[7]  = "a              c c c c c c c c c              c c c c c c c c c            c c c c c c c c c         c c c c c c c c c                                                                                 a";
TileMap[8]  = "a               c c c c c c c c c              c c c c c c c c c            c c c c c c c c c         c c c c c c c c c                                                                                a";
TileMap[9]  = "a                                                                                                                                                                                                      a";
TileMap[10] = "a                                                                                                                                                                                                      a";
TileMap[11] = "a                                                                                                                                                                                                      a";
TileMap[12] = "a                                                                                                                                                                                                      a";
TileMap[13] = "a                                                                                                                                                                                                      a";
TileMap[14] = "a                                                                                                                                                                                                      a";
TileMap[15] = "a                                                                                                                                                                                          M           a";
TileMap[16] = "a                                                                                                                                                                                                      a";
TileMap[17] = "a                                                                                                                                                                                                      a";
TileMap[18] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
TileMap[19] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[20] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[21] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[22] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[23] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[24] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[25] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
TileMap[26] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
}
void Drawing_Map::walkovermap(RenderWindow& window, string TileMap[], Sprite tile, Sprite coins, View& view, Sprite sonic,Sprite finishcoin)
{
	for (int i = 0; i < H; i++) // PRINTING MAP FUNCTION
	{
		for (int j = 0; j < W; j++)
		{
			if (TileMap[i][j] == 'P') {
				tile.setTextureRect(IntRect(1, 1, 16, 16));
				tile.setPosition(j * 15, i * 15);
				window.draw(tile);
			}
			else if (TileMap[i][j] == 'c') {
				coins.setPosition(j * 15, i * 15);
				window.draw(coins);
			}
			else if (TileMap[i][j] == 'M') {

				finishcoin.setPosition(j * 15, i * 15);
				window.draw(finishcoin);
			}
			else if (TileMap[i][j] == 'a') {
				tile.setTextureRect(IntRect(19, 1, 15, 15));
				tile.setPosition(j * 15, i * 15);
				window.draw(tile);
			}
			else if (TileMap[i][j] == 'A') {
				tile.setTextureRect(IntRect(1, 19, 43, 19));
				tile.setPosition(j * 15, i * 15);
				window.draw(tile);
			}
			// collision with coins
			if (sonic.getGlobalBounds().intersects(coins.getGlobalBounds()) && TileMap[i][j] == 'c' )
			{
				coin_sound.play();
				TileMap[i][j] = ' ';
				Player_Score +=50 ;
			}
			// collision with the EndCoin
			if (sonic.getGlobalBounds().intersects(finishcoin.getGlobalBounds()) && TileMap[i][j] == 'M')
			{
				coin_sound.play();
				TileMap[i][j] = ' ';
				Player_Score += 100;
			}
		}
	}
}