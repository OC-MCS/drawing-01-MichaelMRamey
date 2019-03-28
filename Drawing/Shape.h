#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeEnum shape;
	Vector2f pos;
	Color color;
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual void getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{ 
private:
	CircleShape circle;
public:
	void draw(int xpos, int ypos, int RADIUS, int color)
	{
		Vector2f redPos(xpos, ypos);
		circle.setPosition(redPos);
		circle.setRadius(RADIUS);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(Color::Red);
		// for just an outlined button
		circle.setFillColor(Color::Transparent);
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;
public:
	void draw(int xpos, int ypos, int SIZE, int color)
	{
		
	}
};
