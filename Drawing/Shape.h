#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct drawingData
{
	ShapeEnum shape;
	Vector2f pos;
	int color;
};
// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual drawingData getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape circle;
	const int RADIUS = 10;
public:
	Circle(Vector2f pos, Color color)
	{
		circle.setPosition(pos);
		circle.setFillColor(color);
		circle.setRadius(RADIUS);
	}
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}

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
	RectangleShape square;
public:
	Square(Vector2f pos, Color color)
	{
		square.setPosition(pos);
		square.setFillColor(color);
		square.setSize(Vector2f(20, 20));
	}

	void draw(RenderWindow& win)
	{
		win.draw(square);
	}

	drawingData getRecordInfo()
	{
		drawingData result;
		result.color = square.getFillColor().toInteger();
		result.pos = square.getPosition();
		result.shape = SQUARE;
		return result;
	}
};
