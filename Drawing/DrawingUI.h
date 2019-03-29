#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

class DrawingUI
{
private:
	RectangleShape canvas;  //A rect that will represent the canvas
public:
//================================================
// Drawing UI
// Constructor for drawing UI
// Sets the canvas size and position
//================================================
	DrawingUI(Vector2f p)
	{
		canvas.setPosition(p);
		canvas.setSize(Vector2f(500,500));
		canvas.setFillColor(Color::White);
	}
//================================================
// Draw
// Sends data from the vector to be drawn onto
// the canvas.
//================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector<DrawingShape*> list = mgr->listShapes();
		win.draw(canvas);
		for (int i = 0; i < list.size(); i++)
		{
			list[i]->draw(win);
		}
	}
	
//================================================
// isMouseInCanvas
// Determines if the mouse is within the bounds
// of the canvas and returns a bool.
//================================================
	bool isMouseInCanvas(Vector2f mouse)
	{
		bool result = false;
		if (canvas.getGlobalBounds().contains(mouse) && canvas.getGlobalBounds().contains(Vector2f (mouse.x + 20,mouse.y + 20)))
		{
			result = true;
		}
		return result;
	}
};

