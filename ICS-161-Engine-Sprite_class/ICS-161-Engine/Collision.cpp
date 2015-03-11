#include "Collision.h"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

/* Player Values */
double walk_speed = 2;
double run_speed = 2 * walk_speed;
double grounded_speed = 0;
double fall_speed = -11;
double jump_speed = 4;

/* Projectile Values */
double vert_bounce = -6;
double horiz_bounce = -3;
std::vector<double> reflectfront = { -3, -3, -0.1 };
std::vector<double> reflectback = { 3, 3, 0.1 };
std::vector <double> reflecttop = { 6, 0.1, 0.1 };

double setMoveSpeed(double speed, bool left, bool right)
{
	if (left)
	{
		speed = -speed;
	}

	return speed;
}

double setStateSpeed(double speed)
{
	return speed;
}

double setBounceSpeed(double speed, std::string event)
{
	if (event == "ground")
	{
		return speed;
	}

	return speed;
}

std::vector<double> Reflect(std::vector<double> reflect)
{
	return reflect;
}
//
//int setGroundedSpeed(int speed)
//{
//	return grounded_speed;
//}
//
//int setJumpSpeed(int speed)
//{
//	return jump_speed;
//}
//
//int setFallSpeed(int speed)
//{
//	return fall_speed;
//}
