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
public:
	virtual void draw(RenderWindow& win) = 0;
	//virtual void getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape circle;
	const int RADIUS = 20;
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


};

class Square : public DrawingShape
{
private:
	RectangleShape square;
public:
	void draw()
	{

	}
};
