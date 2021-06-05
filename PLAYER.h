#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class PLAYER
{
public:

	PLAYER(Texture& image);
	void update(float time);

	Sprite sprite;

	float dx, dy; // speed on x_axis & speed on y_axis
	float Running_frame = 0, Standing_frame = 0; // frame change while running & frame change while standing
	bool onGround, direction; // if onground or jumping & if moving right or left
	int left = 15, right = 2955, ground = 232; //  borders for collision
	int dxdis = 0; // player move distance
};