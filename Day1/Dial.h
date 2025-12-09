#include <vector>
#include <string>
using namespace std;
#pragma once

class Dial {
private:
	int position;
	int maxPosition = 99;
	int timesLeftAtZero = 0;
	vector<int> linesWhereLeftAtZero;

public:
	Dial();
	void rotateRight(int clicks);
	void rotateLeft(int clicks);
	int getCurrentPosition();
	void processRotations(vector<string> rotations);
	int getTimesLeftAtZero();
};