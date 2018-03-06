#define Tangent
//I used this header file to declare all of my functions

float getInput();
float checkInput(float s_x2, float s_y2, float s_x1, float s_y1);
float distanceFormula(float s_x2, float s_y2, float s_x1, float s_y1);
float findOrientation();
int findSecond(int x, float y, float s_x2, float s_y2, float s_x1, float s_y1, int sort);
float slopeEquation(float s_x2, float s_y2, float s_x1, float s_y1, float g_w1, int sort);
float findB(float m, float s_y1, float s_x1);
//int verticalSlope(float s_x2, float s_y2, float s_x1, float s_y1);


