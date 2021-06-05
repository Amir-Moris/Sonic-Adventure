#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
using namespace std;
using namespace sf;

class Play_window
{
public:
	Play_window(RenderWindow& window);
	void walkovermap(RenderWindow& window, string TileMap[], Sprite tile, Sprite s, View& view);
	
private:
	string TileMap[28];
	Texture Sonic, tileSet, Coins, Coin;
	Clock clock;
	int Best_Score = 0;
};