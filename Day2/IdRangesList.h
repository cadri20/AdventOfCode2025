#pragma once
#include "IdRange.h"
#include <vector>
class IdRangesList {
private:
	vector<IdRange> ranges;
public:
	IdRangesList(vector<string> ranges);
	long long sumInvalidRanges();
};