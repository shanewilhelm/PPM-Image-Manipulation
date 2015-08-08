/**********************************************************************************************
Assignment: CptS 122 Assignment 4.  

Description: This program adds simple effects to a PPM image.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 4 Hours

In completing this program, I received help from the following people: Nobody 
**********************************************************************************************/

#ifndef IMAGE_EFFECTS_H
#define IMAGE_EFFECTS_H

#include "SimpleImageEffect.h"
#include <random>

using namespace std;

class removeBlueEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			points[i].setBlue(0);
		}
	}
};

class removeRedEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			points[i].setRed(0);
		}
	}
};

class removeGreenEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			points[i].setGreen(0);
		}
	}
};

class GreyscaleEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			int averageValue = (points[i].getRed() + points[i].getGreen() + points[i].getBlue()) / 3;
			points[i].setRed(averageValue);
			points[i].setGreen(averageValue);
			points[i].setBlue(averageValue);
		}
	}
};

class HighContrastEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			if(points[i].getRed() >= (255/2))
			{
				points[i].setRed(255);
			}
			else
			{
				points[i].setRed(0);
			}

			if(points[i].getGreen() >= (255/2))
			{
				points[i].setGreen(255);
			}
			else
			{
				points[i].setGreen(0);
			}

			if(points[i].getBlue() >= (255/2))
			{
				points[i].setBlue(255);
			}
			else
			{
				points[i].setBlue(0);
			}
		}
	}
};

class RandomNoiseEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			int randomValue = (rand() % 21) - 10;
			int red = 0;
			int green = 0;
			int blue = 0;

			red = points[i].getRed();
			green = points[i].getGreen();
			blue = points[i].getBlue();

			red += randomValue;
			green += randomValue;
			blue += randomValue;

			if(red < 0)
			{
				red = 0;
			}
			else if (red > 255)
			{
				red = 255;
			}

			if(green < 0)
			{
				green = 0;
			}
			else if (green > 255)
			{
				green = 255;
			}

			if(blue < 0)
			{
				blue = 0;
			}
			else if (blue > 255)
			{
				blue = 255;
			}

			
			points[i].setGreen(green);
			points[i].setBlue(blue);
		}
	}
};

class NegateBlueEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			int blue = 255 - points[i].getBlue();
			
			points[i].setBlue(blue);
		}
	}
};

class NegateGreenEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			int green = 255 - points[i].getGreen();
			
			points[i].setGreen(green);
		}
	}
};

class NegateRedEffect
	:public SimpleImageEffect
{
public: 
	void processImage(Point points[], const int &num_inputs)
	{
		for(int i = 0; i < num_inputs; i++)
		{
			int red = 255 - points[i].getRed();

			points[i].setRed(red);
		}
	}
};

#endif // !IMAGE_EFFECTS_H
