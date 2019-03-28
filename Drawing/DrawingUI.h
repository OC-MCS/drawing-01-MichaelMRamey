#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:

public:
	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		RectangleShape canvas;
		Vector2f canvasPos(250, 50);
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Black);
		canvas.setOutlineThickness(10);
		canvas.setSize(Vector2f(500, 500));
		canvas.setFillColor(Color::White);
		win.draw(canvas);

	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool result = 0;
		return result; // just to make it compile
	}

};

