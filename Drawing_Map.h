#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>

#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Drawing_Map
{
public:
	Drawing_Map(string TileMap[]);
	void walkovermap(RenderWindow& window, string TileMap[], Sprite tile, Sprite coins, View& view, Sprite sonic, Sprite finishcoin);

	int Player_Score = 0;
	Sound coin_sound;
	SoundBuffer COIN;
private:
	int H = 27, W = 200, Best_Score = 0;

};