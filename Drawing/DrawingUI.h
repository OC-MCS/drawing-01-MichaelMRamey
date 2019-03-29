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
		Vector2f canvasPos(250, 0);
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Black);
		canvas.setOutlineThickness(3);
		canvas.setSize(Vector2f(600,600));
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
		if (canvas.getGlobalBounds().contains(mouse))
		{
			result = true;
		}
		return result;
	}
};

