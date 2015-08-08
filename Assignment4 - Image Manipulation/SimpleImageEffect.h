/**********************************************************************************************
Assignment: CptS 122 Assignment 4.  

Description: This program adds simple effects to a PPM image.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 4 Hours

In completing this program, I received help from the following people: Nobody 
**********************************************************************************************/

#ifndef SIMPLE_IMAGE_EFFECT_H
#define SIMPLE_IMAGE_EFFECT_H

#include "Point.h"

using namespace std;

class SimpleImageEffect
	:public Point
{
public:
	virtual void processImage(Point points[], const int &num_inputs) = 0;
};

#endif // !SIMPLE_IMAGE_EFFECT_H
