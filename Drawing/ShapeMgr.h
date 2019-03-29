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
	vector<DrawingShape*> shapes;  //Vector of pointers to drawingShapes.  Will hold a pointer to every shape drawn on the canvas
public:
	//================================================
	// addShape
	// Takes a position, shapeEnum, and color.
	// Dynamically allocates the shape cooresponding
	// to the data passed and pushes to the vector
	//================================================
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
	//================================================
	// listShapes
	// func to return the vector
	//================================================
	const vector<DrawingShape*>& listShapes()
	{
		return shapes;
	}
	//================================================
	// readData
	// For reading data from file.  Reads in all of
	// the shapeMgr data from the file.
	//================================================
	void readData(fstream& file)
	{
		drawingData temp;
		while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.pos, temp.shape, Color(temp.color));
		}
	}
	//================================================
	// writeData
	// For writing data to the file.  Writes all of
	// data concerning shapes on the canvas to the
	// file.
	//================================================
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
