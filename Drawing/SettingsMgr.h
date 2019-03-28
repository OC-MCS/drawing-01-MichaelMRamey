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
	int currentColor;
	int currentShape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
	}

	Color getCurColor()
	{
		return Color::Blue; // just to make it compile 
	}


	ShapeEnum getCurShape()
	{
		return ShapeEnum::CIRCLE; // just to make it compile;
	}

};
