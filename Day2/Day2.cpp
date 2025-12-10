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
    if (!file.is_open())
        return {}; 

    std::stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    vector<string> tokens;
    size_t start = 0;
    size_t pos;

    while ((pos = content.find(',', start)) != string::npos) {
        tokens.push_back(content.substr(start, pos - start));
        start = pos + 1;
    }

    if (start < content.size()) {
        tokens.push_back(content.substr(start));
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
