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

		if (whichShape == SQUARE)
		{
			Square* square;
			square = new Square(pos, color);
			shapes.push_back(square);
		}
	}

	const vector<DrawingShape*>& listShapes()
	{
		return shapes;
	}

	void readData(fstream& file)
	{
		drawingData temp;
		while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.pos, temp.shape, Color(temp.color));
		}
	}

	void writeData(fstream& file)
	{
		drawingData temp;
		for (int i = 0; i < shapes.size(); i++)
		{
			temp = shapes[i]->getRecordInfo();
			file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

};
