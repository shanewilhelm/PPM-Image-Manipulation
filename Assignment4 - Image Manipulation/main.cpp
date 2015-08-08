/**********************************************************************************************
Assignment: CptS 122 Assignment 4.  

Description: This program adds simple effects to a PPM image.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 4 Hours

In completing this program, I received help from the following people: Nobody 
**********************************************************************************************/

#include "ImageEffects.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

int main(void)
{
	ifstream inputFile;
	ofstream outputFile;
	fstream tempFile("temp.ppm");
	fstream tempFile2("temp2.ppm");
	string userInput = "";

	cout << "Enter input file: ";
	getline(cin, userInput);
	inputFile.open(userInput);

	cout << "Enter output file: ";
	getline(cin, userInput);
	outputFile.open(userInput);

	//Copy header information to tempFile
	while(inputFile.good())
	{
		string line = "";
		getline(inputFile, line);
		tempFile << line << "\n";
	}

	inputFile.clear();
	inputFile.seekg(0, inputFile.beg);
	int numColumns = 0;
	int numRows = 0;
	for(int i = 0; i < 3; i++)
	{
		string line = "";
		getline(inputFile, line);

		if(1 == i)
		{
			stringstream ss(line);
			ss >> numColumns >> numRows;
		}
	}

	//Create an array of points that will be altered by a user's chosen effects.
	Point *myPoints = new Point[numColumns];

	SimpleImageEffect *effectArray[9] = {new removeRedEffect, new removeGreenEffect, new removeBlueEffect, new NegateRedEffect, new NegateGreenEffect, new NegateBlueEffect, new RandomNoiseEffect, new HighContrastEffect, new GreyscaleEffect};

	int selection = 0;
	do
	{
		cout << "** Effects **" << endl;
		cout << "\t1. Remove Red" << endl;
		cout << "\t2. Remove Green" << endl;
		cout << "\t3. Remove Blue" << endl;
		cout << "\t4. Negate Red" << endl;
		cout << "\t5. Negate Green" << endl;
		cout << "\t6. Negate Blue" << endl;
		cout << "\t7. Add Noise" << endl;
		cout << "\t8. High Contrast" << endl;
		cout << "\t9. Convert to Grayscale" << endl;
		cout << "\t-1. Exit Program" << endl;

		cout << "Selection: ";
		getline(cin, userInput);
		try
		{
			selection = stoi(userInput);
		}
		catch(...)
		{
			selection = 0; //Having a value of 0 is a NULL selection that will do nothing to the image.
		}

		if(selection <= 0 || selection > 9)
		{
			//Do nothing
		}
		else //selection is valid.
		{
			//Go to the beginning and move past the 'header' information contained in the file.
			tempFile.clear();
			tempFile.seekp(tempFile.beg);
			for(int i = 0; i < 3; i++)
			{
				string line = "";
				getline(tempFile, line);
			}

			//Seek to beginning of file and set up 'header' information
			tempFile2.clear();
			tempFile2.seekp(tempFile2.beg);
			tempFile2 << "P3\n" << numColumns << " " << numRows << "\n255";

			while(tempFile.good())
			{
				//Copy the red, green, and blue values for every pixel within a column from the tempFile(input file) to an array of Points.
				for (int i = 0; i < numColumns; i++)
				{
					int red, green, blue;
					tempFile >> red >> green >> blue;

					myPoints[i].setRed(red);
					myPoints[i].setGreen(green);
					myPoints[i].setBlue(blue);
				}

				//Implement the specified effect on the column
				effectArray[(selection - 1)]->processImage(myPoints, numColumns);

				//Write the changed points to tempFile2
				for (int i = 0; i < numColumns; i++)
				{
					if(i % 5 == 0)
					{
						tempFile2 << "\n";
					}
					
					tempFile2 << myPoints[i].getRed() << " " << myPoints[i].getGreen() << " " << myPoints[i].getBlue() << " ";
				}
			}

			//Seek back to beginning of both temp files, copy temp2 to temp.
			tempFile.clear();
			tempFile.seekp(tempFile.beg);
			tempFile2.clear();
			tempFile2.seekp(tempFile2.beg);
			while(tempFile2.good())
			{
				string line = "";
				getline(tempFile2, line);
				tempFile << line << "\n";
			}
		}

	}while(selection != -1);
		
	cout << "Exiting Program..." << endl;
	
	//Seek to beginning of tempFile2
	tempFile2.clear();
	tempFile2.seekp(tempFile2.beg);

	//Copy tempFile2 to the final "output.ppm" file
	while(tempFile2.good())
	{
		string line = "";
		getline(tempFile2, line);
		outputFile << line << "\n";
	}

	//Clean-Up
	delete[] myPoints;
	for(int i = 0; i < 9; i++)
	{
		delete effectArray[i];
	}
	inputFile.close();
	outputFile.close();
	tempFile.close();
	tempFile2.close();

	return 0;
}