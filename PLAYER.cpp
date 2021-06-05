#include <SFML\Graphics.hpp>
#include <iostream>
#include "PLAYER.h"
using namespace std;
using namespace sf;

PLAYER::PLAYER(Texture& img)
{
	sprite.setTexture(img);
	dx = dy = 0;
}
void PLAYER::update(float time)
{
	// Animation
	if (direction) // right
	{ 
		if (dx == 0 && onGround) // standing
		{ 
			sprite.setTextureRect(IntRect(int(Standing_frame) * 31.6, 41, 30, 40));
			Standing_frame += 0.1;
			if (Standing_frame > 6) Standing_frame -= 6;
		}
		else // moving
		{  
			if (onGround)
				sprite.setTextureRect(IntRect(35 * int(Running_frame), 0, 37, 40));
			else // jumping vertically
				sprite.setTextureRect(IntRect(0, 0, 35, 40));
		}
	}
	else // left
	{ 
		if (dx == 0 && onGround) // standing
		{ 
			sprite.setTextureRect(IntRect(int(Standing_frame) * 31.6 + 31, 41, -31, 40));
			Standing_frame += 0.1;
			if (Standing_frame > 6) Standing_frame -= 6;
		}
		else // moving
		{
			if (onGround)
				sprite.setTextureRect(IntRect(35 * int(Running_frame) + 37, 0, -37, 40));
			else // jumping vertically
				sprite.setTextureRect(IntRect(32, 0, -32, 40)); 
		}
	}

	if (!onGround) {
		dy += (0.0005 * time); // projectile motion equation
	}
	float newTop = sprite.getPosition().y + dy * time;
	onGround = false;
	// ground level
	if (newTop >= ground) {
		newTop = ground;
		dy = 0;
		onGround = true;
	}
	// left border
	if (sprite.getPosition().x < left) {
		dx = 0;
		sprite.setPosition(left, sprite.getPosition().y);
	}
	// right border
	if (sprite.getPosition().x > right) {
		dx = 0;
		sprite.setPosition(right, sprite.getPosition().y);
	}
	sprite.setPosition(sprite.getPosition().x, newTop);
	// time to stop after moving action
	dxdis = dxdis - 1;
	if (dxdis == 0)
		dx = 0;

	sprite.move(dx, 0);
}