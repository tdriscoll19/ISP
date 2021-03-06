//		This program takes a point on a parabola and the focus of that parabola and uses the data to find a 
//line tangent to the parabola through the point
//below are the steps that the program carries out

//1- takes in the input of the focus and point on the parabola from the user- getInput()
//2- give the user an oppurtunity to check that their imput was correct- checkInput()
//3- takes the distance from the point to the focus- distanceFormula()
//4- takes imput from the user regarding the orientation of the parabola- findOrientation()- in orientation.cpp
//5- finds the second point on the line that is tangent to the parabola by subtracting the distance from distanceFormula() from the focus
//6- takes the point on the parabola and the one found in step 5 and plugs them into slope formula- slopeEquation()
//7- takes the slope and the original point, puts them into slope formula and solves for b (the y intercept)- findB()
//		and outputs the final equation through the console.

#include "stdafx.h"
#include <iostream>
#include "Tangent.h"
#include <math.h>
#include <string>

float s_x2; //x coordinate for the focus
float s_y2; //y coordinate for the focus
float s_x1; //x coordinate for the parabola
float s_y1; //y coordinate for the parabola
int sort;   // used for conditional statements in slopeEquation()
float g_w1; //the other coordinate for the second point- could be the x or y depending on the orientation

int main()
{
	getInput();
	checkInput(s_x2, s_y2, s_x1, s_y1);
	findB(s_x1, s_y1, slopeEquation(s_x2, s_y2, s_x1, s_y1, g_w1, findSecond(findOrientation(), distanceFormula(s_x2, s_y2, s_x1, s_y1), s_x2, s_y2, s_x1, s_y1, sort)));
    return 0;
}

float getInput()
{ 
	std::cout << "input the X-Value for the focus""\n";
	std::cin >> s_x2;
	std::cout << "input the Y-Value for the focus""\n";
	std::cin >> s_y2;
	std::cout << "input the X-Value for the point on the graph""\n";
	std::cin >> s_x1;
	std::cout << "input the Y-Value for the point on the graph""\n";
	std::cin >> s_y1;
	std::cin.ignore(32767, '\n');
	return 0;
}



float checkInput(float s_x2, float s_y2, float s_x1, float s_y1)
{
	//returns the user to the beginning of the program if their intserted point was incorrect
	std::cout << "You Entered f(" << s_x2 << "," << s_y2 << ")" "\n"; 
	std::cout << "You entered p(" << s_x1 << "," << s_y1 << ")" "\n";
	std::cout << "is this correct? Type yes/no.\n";
	std::string x;
	std::getline(std::cin, x);
	if (!x.compare("yes"))
	{
		return 0;
	}
		else
			main();
	return 0;
}

float distanceFormula(float s_x2, float s_y2, float s_x1, float s_y1)
{
	//jump over to orientation.cpp after this function
	float y;
	y = s_y2 - s_y1;
	y = y * y;
	float x;
	x = s_x2 - s_x1;
	x = x * x;
	float c;
	c = x + y;
	float dist;
	dist = pow(c, .5);
	std::cout << "the distance between the point and the focus is:\n" << dist <<std::endl;
	//std::cin.ignore(32767, '\n');
	return dist;
}

int findSecond(int x, float y, float s_x2, float s_y2, float s_x1, float s_y1, int sort) 
//where x is the return from findOrientation() and y is the distance from distanceFormula()
//the orientation depends on which coordinate the distance is subtracted from to find the second point, hence the switch statements
//the return value enables the next function to know which coordinates to use when finding the slope
{
	float m;
	switch (x)
	{
	case (1):
		g_w1 = s_x2 + y;
		std::cout << "the second point is:" << g_w1 << "," << s_y2 << "\n";
		sort = 1;
		return sort;
		break;
	case (2):

		g_w1 = s_x2 - y;
		std::cout << "the second point is:" << g_w1 << "," << s_y2 << "\n";
		sort = 2;
		return sort;
		break;
	case (3):
		g_w1 = s_y2 - y;
		std::cout << "the second point is:" << s_x2 << "," << g_w1 << "\n";
		sort = 3;
		return sort;
		break;
	case (4):

		g_w1 = s_y2 + y;
		std::cout << "the second point is:" << s_x2 << "," << g_w1 << "\n";
		sort = 4;
		return sort;
		break;
	}
	return 0;
	// jump back to orientation.cpp after this
}