#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:

public:
	SettingsUI(SettingsMgr *mgr)
	{

	}
	void handleMouseUp(Vector2f mouse)
	{
		/*if (redBtn.getGlobalBounds().contains(mouse))
			currentColor = "red";*/
	}

	void draw(RenderWindow& win)
	{
		// first have to load font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\papyrus.ttf"))
			die("couldn't load font");

		// title
		Text selectedColor("Selected Color", font, 25);
		selectedColor.setPosition(30, 25);
		win.draw(selectedColor);

		Text selectedShape("Selected Shape", font, 25);
		selectedShape.setPosition(30, 300);
		win.draw(selectedShape);


		//Red Button
		CircleShape redBtn;
		Vector2f redPos(100, 70);
		redBtn.setPosition(redPos);
		redBtn.setRadius(20);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		// for just an outlined button
		redBtn.setFillColor(Color::Transparent);
		win.draw(redBtn);


		//Green Button
		CircleShape greenBtn;
		Vector2f greenPos(100, 140);
		greenBtn.setPosition(greenPos);
		greenBtn.setRadius(20);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		// for just an outlined button
		greenBtn.setFillColor(Color::Transparent);
		win.draw(greenBtn);


		// Blue Button
		CircleShape blueBtn;
		Vector2f bluePos(100, 210);
		blueBtn.setPosition(bluePos);
		blueBtn.setRadius(20);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		// for just an outlined button
		blueBtn.setFillColor(Color::Transparent);
		win.draw(blueBtn);

		
		// Circle Button
		CircleShape circleBtn;
		Vector2f circlePos(100, 370);
		circleBtn.setPosition(circlePos);
		circleBtn.setRadius(20);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		// for just an outlined button
		circleBtn.setFillColor(Color::Transparent);
		win.draw(circleBtn);


		// Square Button
		RectangleShape squareBtn;
		Vector2f sqPos(100, 440);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setFillColor(Color::Black);
		win.draw(squareBtn);

		
	}

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}
};
