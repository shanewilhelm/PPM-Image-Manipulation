/**********************************************************************************************
Assignment: CptS 122 Assignment 4.  

Description: This program adds simple effects to a PPM image.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 4 Hours

In completing this program, I received help from the following people: Nobody 
**********************************************************************************************/

#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Point
{
private:
	int _x;
	int _y;
	int _z;
	int _red;
	int _green;
	int _blue;

public:
	Point(int x = 0, int y = 0, int z = 0, int red = 0, int green = 0, int blue = 0)
	{
		_x = x;
		_y = y;
		_z = z;
		_red = red;
		_green = green;
		_blue = blue;
	}

	int getX() const
	{
		return _x;
	}

	int getY() const
	{
		return _y;
	}

	int getZ() const
	{
		return _z;
	}

	int getRed() const
	{
		return _red;
	}

	int getGreen() const
	{
		return _green;
	}

	int getBlue() const
	{
		return _blue;
	}

	void setX(int x) 
	{
		_x = x;
	}

	void setY(int y) 
	{
		_y = y;
	}

	void setZ(int z) 
	{
		_z = z;
	}

	void setRed(int red) 
	{
		_red = red;
	}

	void setGreen(int green) 
	{
		_green = green;
	}

	void setBlue(int blue) 
	{
		_blue = blue;
	}

	string toString() const
	{
		string text = "";
		stringstream ss(text);

		ss << _red << " " << _green << " " << _blue << " ";

		return ss.str();
		
	}

	Point* fromString(string text)
	{
		//From a PPM string consisting of "(redValue) (greenValue) (blueValue) "
		stringstream ss(text);
		int red, green, blue;

		ss >> red >> green >> blue;
		Point myPoint(0,0,0, red, green, blue);
		return &myPoint;
	}

};


#endif // !POINT_H
