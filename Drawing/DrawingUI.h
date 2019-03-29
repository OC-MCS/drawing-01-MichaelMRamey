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
	RectangleShape canvas;
public:
	DrawingUI(Vector2f p)
	{
		canvas.setPosition(p);
		canvas.setSize(Vector2f(500,500));
		canvas.setFillColor(Color::White);
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector<DrawingShape*> list = mgr->listShapes();
		win.draw(canvas);
		for (int i = 0; i < list.size(); i++)
		{
			list[i]->draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mouse)
	{
		bool result = false;
		if (canvas.getGlobalBounds().contains(mouse) && canvas.getGlobalBounds().contains(Vector2f (mouse.x + 20,mouse.y+20)))
		{
			result = true;
		}
		return result;
	}
};

