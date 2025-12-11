#include "Machine.h"

Machine::Machine(vector<string> buttonWiringSchematics, int lightsNumber): lights(lightsNumber, false)
{
	for (auto buttonWiringSchematic : buttonWiringSchematics) {
		buttons.push_back(new Button(buttonWiringSchematic));
	}
}

void Machine::pressButton(int buttonNumber)
{
	buttons[buttonNumber]->press(lights);
}

string Machine::getLights()
{
	string result = "";
	for (auto light : lights) {
		result += light ? "#" : ".";
	}
	return result;
}

vector<Button*> Machine::getButtons()
{
	return buttons;
}
