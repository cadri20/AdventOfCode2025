#include "Button.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

Button::Button(string wiringSchematics)
{
    std::string s = wiringSchematics;

    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());

    if (s.size() < 2 || s.front() != '(' || s.back() != ')') {
        throw std::runtime_error("Formato inválido: se esperaba (a,b,c...)");
    }

    s = s.substr(1, s.size() - 2);

    std::vector<int> numbers;
    std::stringstream ss(s);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            numbers.push_back(std::stoi(token));
        }
    }

    lightsToToggle = numbers;
}

void Button::press(vector<bool>& lights)
{
	for (auto lightToToggle: lightsToToggle) {
		lights[lightToToggle] = !lights[lightToToggle];
	}
}
