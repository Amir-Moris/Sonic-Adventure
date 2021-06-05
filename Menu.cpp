#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Menu.h"
using namespace std;
using namespace sf;
#define MAX_buttons  3

Menu::Menu(int width, int height)
{
	if (!font.loadFromFile("GoblinOne-Regular.ttf")) {}

	// highscore text
	highscore.setFont(font);
	highscore.setFillColor(Color::Black);
	highscore.setString("Highest Score :");
	highscore.setCharacterSize(15);
	highscore.setPosition(Vector2f(width - 280, height - 550));
	
	// highscore number
	ifstream OutBestScore("High_Score.txt"); // get the best score from the file
	OutBestScore >> Best_Score;
	stringstream s;
	s << Best_Score;
	Max_Score.setString(s.str());

	Max_Score.setFont(font);
	Max_Score.setFillColor(Color::Black);
	Max_Score.setStyle(Text::Regular);
	Max_Score.setCharacterSize(18);
	Max_Score.setPosition(Vector2f(500, 48));

	// making PLAY button
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Blue);
	mainmenu[0].setString("PLAY");
	mainmenu[0].setCharacterSize(50);
	mainmenu[0].setPosition(Vector2f(width / 2 - 270, height / (MAX_buttons + 1)));

	// making Credit button
	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::White);
	mainmenu[1].setString("Credit");
	mainmenu[1].setCharacterSize(50);
	mainmenu[1].setPosition(Vector2f(width / 2 - 270, height / (MAX_buttons + 1) * 2));

	// making Exit button
	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::White);
	mainmenu[2].setString("Exit");
	mainmenu[2].setCharacterSize(40);
	mainmenu[2].setPosition(Vector2f(width / 2 - 270, height / (MAX_buttons + 1) * 3));

	buttonSelected = 0;  // to make starting position is PLAY button
}

Menu::~Menu()
{
}
// function of main menu 
void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
		window.draw(mainmenu[i]);

	window.draw(highscore);
	window.draw(Max_Score);
}
// function of moving DOWN
void Menu::movedown()
{
	if (buttonSelected + 1 <= MAX_buttons)      // check if not on the EXit button
	{
		mainmenu[buttonSelected].setFillColor(Color::White);      // to change the previous item color
		buttonSelected++;       // moving down
		if (buttonSelected == 3)
			buttonSelected = 0;

		mainmenu[buttonSelected].setFillColor(Color::Blue);     // change new selected button to blue
	}
}
// function of moving up
void Menu::moveup()
{
	if (buttonSelected - 1 >= -1)      // check if not on the play button
	{
		mainmenu[buttonSelected].setFillColor(Color::White);      // to change the previous item color
		buttonSelected--;      // moving up
		if (buttonSelected == -1)
			buttonSelected = 2;
			
		mainmenu[buttonSelected].setFillColor(Color::Blue);     // change new selected button to blue
	}
}
void Menu::creditsWindow()
{
	RenderWindow window_credit(VideoMode(600.f, 600.f), "Sonic Adventure", Style::Titlebar);
	RectangleShape background(Vector2f(600.0f, 600.0f));
	Texture back;
	back.loadFromFile("imgs/background.jpg");
	background.setTexture(&back);
	while (window_credit.isOpen())
	{
		Event event;
		while (window_credit.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window_credit.close();
			if (!font.loadFromFile("GoblinOne-Regular.ttf")) {}

			Names[0].setFont(font);
			Names[0].setFillColor(Color::White);
			Names[0].setString("Amir Moris");
			Names[0].setCharacterSize(30);
			Names[0].setPosition(Vector2f(35.f, 100.f));

			Names[1].setFont(font);
			Names[1].setFillColor(Color::White);
			Names[1].setString("Kirollos Aziz");
			Names[1].setCharacterSize(30);
			Names[1].setPosition(Vector2f(35.f, 170.f));

			Names[2].setFont(font);
			Names[2].setFillColor(Color::White);
			Names[2].setString("Michel Magdy");
			Names[2].setCharacterSize(30);
			Names[2].setPosition(Vector2f(35.f, 240.f));

			Names[3].setFont(font);
			Names[3].setFillColor(Color::White);
			Names[3].setString("Mina Girgis");
			Names[3].setCharacterSize(30);
			Names[3].setPosition(Vector2f(35.f, 310.f));

			Names[4].setFont(font);
			Names[4].setFillColor(Color::White);
			Names[4].setString("Mina Hisham");
			Names[4].setCharacterSize(30);
			Names[4].setPosition(Vector2f(35.f, 380.f));

			Names[5].setFont(font);
			Names[5].setFillColor(Color::White);
			Names[5].setString("Samy Samer");
			Names[5].setCharacterSize(30);
			Names[5].setPosition(Vector2f(35.f, 450.f));

			Names[6].setFont(font);
			Names[6].setFillColor(Color::Blue);
			Names[6].setString("Press ESC to return");
			Names[6].setCharacterSize(15);
			Names[6].setPosition(Vector2f(35.f, 520.f));

			if (event.key.code == Keyboard::Escape)
			{
				window_credit.close();
			}
		}

		window_credit.clear();
		window_credit.draw(background);
		for (int i = 0; i < 7; i++)
		{
			window_credit.draw(Names[i]);
		}
		window_credit.display();
	}
}