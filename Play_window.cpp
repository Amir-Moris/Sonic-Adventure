#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Play_window.h"
#include "Drawing_Map.h"
#include "PLAYER.h"
using namespace std;
using namespace sf;

Play_window::Play_window(RenderWindow& window)
{
	View view(Vector2f(250, 250), Vector2f(400, 400)); // VIEW FUNCTION

	// Sonic movement_sprite sheet
	Sonic.loadFromFile("imgs/Sonic.png");
	PLAYER p(Sonic);

	// ground_spritesheet
	tileSet.loadFromFile("imgs/spritesheet.png");
	Sprite tile(tileSet);

	// coins_spritesheet
	Coins.loadFromFile("imgs/coins.png");
	Coin.loadFromFile("imgs/EndCoin.png");
	Sprite Coins_spr;
	Coins_spr.setTexture(Coins);
	Sprite Coin_spr;
	Coin_spr.setTexture(Coin);

	Drawing_Map MAP(TileMap);

	// show Score text
	Text score;
	Font font;
	if (!font.loadFromFile("GoblinOne-Regular.ttf")) {}
	score.setFont(font);
	score.setFillColor(Color::White);
	score.setStyle(Text::Regular);
	score.setString("Score:");
	score.setCharacterSize(20);

	// show score number
	Text scoreCurrent;
	scoreCurrent.setFont(font);
	scoreCurrent.setFillColor(Color::White);
	scoreCurrent.setStyle(Text::Regular);
	scoreCurrent.setCharacterSize(20);

	float Frame_Rate = 0;

	while (window.isOpen())
	{
		Event event;

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800; // jumping speed

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
				window.close();
			}
			// movement
			if (Keyboard::isKeyPressed(Keyboard::A) && p.sprite.getPosition().x > 50) // left
			{
				Frame_Rate += 0.2;
				if (Frame_Rate > 9) Frame_Rate -= 9;
				p.Running_frame = Frame_Rate;
				p.direction = 0;
				p.dx = -10; // moving speed left
				p.dxdis = 5;
			}
			if (Keyboard::isKeyPressed(Keyboard::D) && p.sprite.getPosition().x < 2950) // right
			{
				Frame_Rate += 0.2;
				if (Frame_Rate > 9) Frame_Rate -= 9;
				p.Running_frame = Frame_Rate;
				p.direction = 1;
				p.dx = 10; // moving speed right
				p.dxdis = 5;
			}
			if (Keyboard::isKeyPressed(Keyboard::W) && p.onGround) // jump
			{
				p.dy = -0.4; // speed on y-axis
				p.onGround = false;
			}
		}
		window.clear(Color(107, 140, 255));
		p.update(time);

		window.draw(score);
		window.draw(scoreCurrent);

		if (p.sprite.getPosition().x > 150 && p.sprite.getPosition().x < 2700)
		{
			view.setCenter(p.sprite.getPosition().x + 90, 200); //  screen view >> mid
			// score view >> mid
			score.setPosition(p.sprite.getPosition().x - 110, 20);
			scoreCurrent.setPosition(p.sprite.getPosition().x - 15, 20);
		}

		else if (p.sprite.getPosition().x >= 2700) // screen view >> right
		{
			view.setCenter(2800, 200);
			// score view >> right
			score.setPosition(2600, 20);
			scoreCurrent.setPosition(2695, 20);
		}

		else
		{
			view.setCenter(200, 200); // screen view >> left
			// score view >> left
			score.setPosition(15, 20);
			scoreCurrent.setPosition(110, 20);
		}

		MAP.walkovermap(window, TileMap, tile, Coins_spr, view, p.sprite, Coin_spr);
		// Convert score-int to string
		stringstream getscore;
		getscore << MAP.Player_Score;
		scoreCurrent.setString(getscore.str());

		window.draw(p.sprite);
		window.setView(view); // RELATED TO VIEW FUNCTION
		window.display();
	}
}