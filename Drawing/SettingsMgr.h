#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color currentColor;  //Var to store current color selected in options
	ShapeEnum currentShape;  //Var to store current shape selected in options
public:
	//================================================
	// SettingsMgr
	// Constructor
	// Sets the current data to the starting data
	//================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}
	//================================================
	// getCurColor
	// A getter that returns the color stored in data
	//================================================
	Color getCurColor()
	{
		Color result;
		result = currentColor;
		return result;
	}
	//================================================
	// getCurShape
	// Getter that returns ShapeEnum in currentShape
	//================================================
	ShapeEnum getCurShape()
	{
		ShapeEnum result;
		result = currentShape;
		return result;
	}
	//================================================
	// setCurColor
	// Setter for currentColor
	//================================================
	void setCurColor(Color input)
	{
		currentColor = input;
	}
	//================================================
	// setCurShape
	// Setter for currentShape
	//================================================
	void setCurShape(ShapeEnum input)
	{
		currentShape = input;
	}
	//================================================
	// readData
	// For reading data from file.  Reads in all of
	// the settingsMgr data from the file.
	//================================================
	void readData(fstream& file)
	{
		int temp;
		file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.read(reinterpret_cast<char*>(&currentShape), sizeof(currentShape));
		currentColor = Color(temp);
	}
	//================================================
	// writeData
	// For writing data to the file.  Writes all of
	// the private data (curColor and shape) to file
	//================================================
	void writeData(fstream& file)
	{
		int temp = currentColor.toInteger();
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.write(reinterpret_cast<char*>(&currentShape), sizeof(currentShape));
	}
};
