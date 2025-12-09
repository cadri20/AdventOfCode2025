#include <string>

#include "Day1.h"
#include <vector>
#include <fstream>
#include "Dial.h"
#include <iostream>
using namespace std;

namespace Day1 {
	vector<string> getInputFromFile(const string& filePath) {
		ifstream file(filePath);
		vector<string> lines;
		string line;
		while (getline(file, line)) {
			lines.push_back(line);
		}

		return lines;
	}

	void Day1::printSolution()
	{
		auto data = getInputFromFile(".\\Day1\\Input.txt");

		Dial dial;
		dial.processRotations(data);

		std::cout << "Solution day 1: " << dial.getTimesLeftAtZero();
	}

}


