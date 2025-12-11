#include <vector>
#include <string>
using namespace std;

#pragma once

class Button {
private:
	vector<int> lightsToToggle;
public:
	Button(string wiringSchematics);
	void press(vector<bool>& lights);
};