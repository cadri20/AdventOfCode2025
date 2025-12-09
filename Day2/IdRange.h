#pragma once
#include <string>
#include <vector>

using namespace std;

class IdRange {
private:
	long long minId;
	long long maxId;
	
	bool isInvalidId(string id);
	
public:
	IdRange(string range);
	vector<string> getInvalidIds();
	long long getSumInvalidIds();
};