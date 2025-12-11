#pragma once
#include "Button.h"
class Machine {
private:
	vector<Button*> buttons;
	vector<bool> lights;
	vector<int> joltages;

public:
	Machine(vector<string> buttonWiringSchematics, int lightsNumber);
	void pressButton(int buttonNumber);
	string getLights();
	vector<Button*> getButtons();
};