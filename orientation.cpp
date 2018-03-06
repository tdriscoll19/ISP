#include "stdafx.h"
#include <iostream>
#include "Tangent.h"
#include <math.h>
#include <string>




float findOrientation()
{
	// has the user input the orientation of the parabola, and allows them to check if they did so correctly
restart:
	std::string a;
	std::string b;
	std::string c;
	std::cout << "is the parabola vertical or horizontal? Enter the orientation\n";
		std::getline(std::cin, a);

		if (!a.compare("horizontal"))
		{
		restart1:
			std::cout << "is the parabola left or right oriented? Enter the orientation\n";
			std::getline(std::cin, b);
			if (!b.compare("left"))
			{
				return 1;
			}
			else if (!b.compare("right"))
			{
				return 2;
			}
			else
			{
				std::cout << "orientation not entered correctly, try again\n";
				goto restart1;
			}
		}
		else if (!a.compare("vertical"))
		{
		restart2:
			std::cout << "is the parabola up or down oriented? Enter the orientation\n";
			std::getline(std::cin, c);
			if (!c.compare("up"))
			{
				return 3;
			}
			else if (!c.compare("down"))
			{
				return 4;
			}
			else
			{
				std::cout << "orientation not entered correctly, try again\n";
				goto restart2;
			} 
		}
		else
		{
			std::cout << "orientation not inserted properly, going back\n";
			goto restart;
		}
		return 0;
		//jump back over to the bottom of tangent line.cpp after this
}



float slopeEquation(float s_x2, float s_y2, float s_x1, float s_y1, float g_w1, int sort)
//finds the slope between the point on the parabola and the point solved for by subtracting the distance from the focus
{
	switch (sort)
	{
		float m; 
	case (1):
		m = ((s_y1 - s_y2) / (s_x1 - g_w1));
		std::cout << "The slope is: " << m << "\n";
		return m;
		break;
	case (2):
		m = ((s_y1 - s_y2) / (s_x1 - g_w1));
		std::cout << "The slope is: " << m << "\n";
		return m;
		break;
	case (3):
		m = ((g_w1 - s_y1) / (s_x2 - s_x1));
		std::cout << "the slope is " << m << "\n";
		return m;
		break;
	case (4):
		m = ((g_w1 - s_y1) / (s_x2 - s_x1));
		std::cout << "the slope is " << m << "\n";
		return m;
		break;
	}
	return 0; 
}

float findB(float s_x1, float s_y1, float m)
{
	// uses the slope (m), and the original point s_x1, s_y1 to find the b- value of the linear equation
	// outputs the final equation to the user, this ends the program!
		float b;
		b = s_y1 - (m*s_x1);
		std::cout << "the b-value is: " << b << "\n";
		std::cout << "the equation of a line tangent to the parabola at the given point is\n";
		if (b > 0)
		{
			std::cout << "y = " << m << "x + " << b << "\n";
		}
		else if (b < 0)
		{
			b = -b;
			std::cout << "y = " << m << "x - " << b << "\n";
		}
		else
		{
			std::cout << "y =" << m << "x\n";
		}
	return 0;
}