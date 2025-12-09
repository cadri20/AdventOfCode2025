#include "Dial.h"
#include <cmath>

Dial::Dial()
{
	position = 50;
}

void Dial::rotateRight(int clicks) {
	position = (position + clicks) % (maxPosition + 1);
	if (position == 0)
		timesLeftAtZero++;
}

void Dial::rotateLeft(int clicks)
{
	position = (position - clicks) % (maxPosition + 1);
	
	if (position == 0)
		timesLeftAtZero++;
}

int Dial::getCurrentPosition()
{
	return position;
}

void Dial::processRotations(vector<string> rotations)
{
	int line = 1;
	for (auto rotation : rotations) {
		char direction = rotation[0];
		int clicks = std::stoi(rotation.substr(1));

		if (direction == 'R')
			rotateRight(clicks);
		else
			rotateLeft(clicks);

		if (position == 0)
			linesWhereLeftAtZero.push_back(line);

		line++;
	}
}

int Dial::getTimesLeftAtZero()
{
	return timesLeftAtZero;
}


