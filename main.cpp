#include <SFML\Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Play_window.h"
using namespace std;
using namespace sf;

int main()
{
	int pagenumber = 0;
	while (true)
	{
		RenderWindow window(VideoMode(600, 600), "Sonic Adventure", Style::Titlebar);

		RectangleShape background(Vector2f(600.0f, 600.0f));
		Texture back;
		back.loadFromFile("imgs/background.jpg");
		background.setTexture(&back);
		Menu MAINMENU(600, 600);
		// sound effects
		Music music, play_music;
		Sound menuS;
		SoundBuffer  menuB;

		music.openFromFile("sound/intro.ogg");
		menuB.loadFromFile("sound/menu.ogg");
		play_music.openFromFile("sound/play.ogg");

		music.play();
		menuS.setBuffer(menuB);
		// open menu
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				// moving through the menu
				if (Keyboard::isKeyPressed(Keyboard::Up)) // up
				{
					MAINMENU.moveup();
					menuS.play(); // sound effect
					break;	
				}
				if (Keyboard::isKeyPressed(Keyboard::Down))// down
				{
					MAINMENU.movedown();
					menuS.play(); // sound effect
					break;
				}

				// choosing the next page 
				if (event.key.code == Keyboard::Return)      //selective button (enter)
				{
					if (MAINMENU.pressedbutton() == 0)       // PLAY button
					{
						window.close();
						pagenumber = 0;
						music.stop();  // Stop Menu Music
						play_music.play(); // play play_music
					}
					if (MAINMENU.pressedbutton() == 1)      // credit button
					{
						window.close();
						pagenumber = 1;
					}
					if (MAINMENU.pressedbutton() == 2)      // EXIT button
					{
						window.close();
						pagenumber = 2;
					}
				}
			}

			window.clear();
			window.draw(background);
			MAINMENU.draw(window);
			window.display();
		}
		if (pagenumber == 0)       // next page after pressing PLAY
		{
			RenderWindow PLAY(VideoMode(1000, 600), "Sonic Adventure", Style::Close);
			// ***************** PLAY ************************
	        Play_window start(PLAY);

		}
		if (pagenumber == 1)  // next page after pressing Credit
		{
			MAINMENU.creditsWindow();
		}
		if (pagenumber == 2)   //next page after pressing EXIT
		{
			break;
		}
	}
}