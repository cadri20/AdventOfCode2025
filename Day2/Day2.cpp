#include "Day2.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "IdRangesList.h"

using namespace std;

vector<string> Day2::getInputFromFile(const string& filePath)
{
	ifstream file(filePath);
	std::stringstream buffer;
	buffer << file.rdbuf();
	string content = buffer.str();
	vector<string> tokens = vector<string>();
	size_t pos = 0;
	while ((pos = content.find(',')) != string::npos) {
		tokens.push_back(content.substr(0, pos));
		content.erase(0, pos + 1);
	}
	
	return tokens;
}

void Day2::printSolution()
{
	auto input = getInputFromFile(".\\Day2\\Input.txt");
	auto rangeList = IdRangesList(input);
	auto sumInvalidIds = rangeList.sumInvalidRanges();

	std::cout << "Solution day 2: " << sumInvalidIds;

}
