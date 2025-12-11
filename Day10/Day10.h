#include "Machine.h"
namespace Day10 {
	void printSolution();

	int findFewestButtonPresses(Machine machine, string finalState);

	int testButtonSequence(Machine machine, vector<int> pressSequence, string finalState);

	vector<vector<int>> getCombinations(int buttonsNumber);

	vector<string> getFinalStatesFromFile();

	vector<vector<string>> getButtonWiredSchematicsFromFile();

}