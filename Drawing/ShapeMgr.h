#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle* circle;
			circle = new Circle(pos, color);
			shapes.push_back(circle);
		}

	}

	const vector<DrawingShape*>& listShapes()
	{
		return shapes;
	}

};
