#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct drawingData  //Struct to be passed to the write functions. data written to file
{
	ShapeEnum shape;
	Vector2f pos;
	int color;
};


class DrawingShape
{
public:
	virtual void draw(RenderWindow& win) = 0;  //Polymorphic func to draw the shape
	virtual drawingData getRecordInfo() = 0;   //Polymorphic func that returns a struct drawing data
};

class Circle : public DrawingShape
{
private:
	CircleShape circle;  //Var to store a circle
	const int RADIUS = 10;  //Const var for radius.  If changed will affect circles drawn on canvas
public:
	//================================================
	// Circle
	// Constructor for a circle.  Takes the position
	// and color and sets the new circle's data to 
	// match that.  Also sets radius.
	//================================================
	Circle(Vector2f pos, Color color)
	{
		circle.setPosition(pos);
		circle.setFillColor(color);
		circle.setRadius(RADIUS);
	}
	// Draw: draws the circle
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}
	//================================================
	// getRecordInfo
	// Creates a temp struct drawingData (to be sent
	// to file), sets it to hold the circle's color,
	// pos and shape, and returns it.
	//================================================
	drawingData getRecordInfo()
	{
		drawingData result;
		result.color = circle.getFillColor().toInteger();
		result.pos = circle.getPosition();
		result.shape = CIRCLE;
		return result;
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;  //Var to hold data for a square.
public:
	//================================================
	// Square
	// Constructor for a Square.  Takes the position
	// and color and sets the new Square's data to 
	// match that.  Also sets the size.
	//================================================
	Square(Vector2f pos, Color color)
	{
		square.setPosition(pos);
		square.setFillColor(color);
		square.setSize(Vector2f(20, 20));
	}
	// Draw: draws the square on the canvas
	void draw(RenderWindow& win)
	{
		win.draw(square);
	}
	//================================================
	// getRecordInfo
	// Creates a temp struct drawingData (to be sent
	// to file), sets it to hold the squares's color,
	// pos and shape, and returns it.
	//================================================
	drawingData getRecordInfo()
	{
		drawingData result;
		result.color = square.getFillColor().toInteger();
		result.pos = square.getPosition();
		result.shape = SQUARE;
		return result;
	}
};
