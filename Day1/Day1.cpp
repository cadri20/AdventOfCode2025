#include <string>

#include "Day1.h"
#include <vector>
#include <fstream>
#include "Dial.h"
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

	int Day1::getSolution()
	{
		auto data = getInputFromFile(".\\Day1\\Input.txt");

		Dial dial;
		dial.processRotations(data);

		return dial.getTimesLeftAtZero();
	}
}


