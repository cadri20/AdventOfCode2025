#include "IdRange.h"

IdRange::IdRange(string range)
{
	auto pos = range.find("-");
	auto minStr = range.substr(0, pos);
	this->minId = stoll(minStr);
	
	auto maxStr = range.substr(pos + 1, range.length());
	this->maxId = stoll(maxStr);
}

vector<string> IdRange::getInvalidIds()
{
	auto ids = vector<string>();
	for (long long id = this->minId; id <= this->maxId; id++) {
		string idStr = to_string(id);
		if (isInvalidId(idStr)) {
			ids.push_back(idStr);
		}
	}

	return ids;
}

long long IdRange::getSumInvalidIds()
{
	long long sum = 0;
	auto invalidIds = getInvalidIds();

	for (auto invalidId : invalidIds) {
		sum += stoll(invalidId);
	}

	return sum;
}

bool IdRange::isInvalidId(string id)
{
	if (id.size() % 2 != 0)
		return false;              

	bool isEqual = true;
	int half = id.size() / 2;
	for (int i = 0; i < half; i++) {
		if (id[i] != id[half + i]) {
			isEqual = false;
			break;
		}
	}

	return isEqual;
}

