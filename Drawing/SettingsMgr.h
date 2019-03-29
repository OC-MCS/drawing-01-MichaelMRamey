#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color currentColor;
	ShapeEnum currentShape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

	Color getCurColor()
	{
		Color result;
		result = currentColor;
		return result;
	}

	ShapeEnum getCurShape()
	{
		ShapeEnum result;
		result = currentShape;
		return result;
	}

	void setCurColor(Color input)
	{
		currentColor = input;
	}

	void setCurShape(ShapeEnum input)
	{
		currentShape = input;
	}
};
