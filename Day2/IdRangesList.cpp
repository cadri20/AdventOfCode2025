#include "IdRangesList.h"
#include <numeric>
#include <ranges>
#include <iostream>

IdRangesList::IdRangesList(vector<string> ranges)
{
	vector<IdRange> ;
	this->ranges.reserve(ranges.size());

	for (string& range : ranges) {
		this->ranges.push_back(IdRange(range));
	}
}

long long IdRangesList::sumInvalidRanges()
{
	long long sum = 0;

	for (auto& range : ranges) {
		auto sumInvalidIds = range.getSumInvalidIds();
		sum += sumInvalidIds;
	}

	return sum;
}
