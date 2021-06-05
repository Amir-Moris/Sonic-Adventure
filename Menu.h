#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
using namespace std;
using namespace sf;
#define MAX_buttons  3

class Menu
{
public :
	Menu(int width, int height);
	void draw(RenderWindow& window);
	void moveup();
	void movedown();
	void creditsWindow();

	int pressedbutton()
	{
		return buttonSelected;
	}
	~Menu();
private :
	int buttonSelected, Best_Score = 0;
	Font font;
	Text mainmenu[MAX_buttons], Names[7], highscore, Max_Score;   // 3 is the max number of buttons , TEAM members are 6
};