#include "End.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
using namespace std;
using namespace sf;

End::End(RenderWindow& window, int curscore)
{
	Font font;
	if (!font.loadFromFile("GoblinOne-Regular.ttf")) {}

	Texture pic;
	pic.loadFromFile("imgs/end.jpg");
	Sprite pic_spr;
	pic_spr.setTexture(pic);

	Text curscore_text;
	stringstream s;
	s << curscore;
	curscore_text.setString(s.str());

	curscore_text.setFont(font);
	curscore_text.setFillColor(Color::White);
	curscore_text.setStyle(Text::Regular);
	curscore_text.setCharacterSize(25);
	curscore_text.setPosition(Vector2f(257, 365));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
				window.close();
			}
		}
		window.clear();
		window.draw(pic_spr);
		window.draw(curscore_text);
		window.display();
	}
}