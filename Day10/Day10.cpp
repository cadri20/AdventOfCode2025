#include "Machine.h"
#include <iostream>
#include <fstream>
#include "Day10.h"
namespace Day10 {
	void printSolution() {
		auto finalStates = getFinalStatesFromFile();
		auto buttonWiredSchematics = getButtonWiredSchematicsFromFile();

		int totalFewestButtonPresses = 0;
		for (int i = 0; i < finalStates.size(); i++) {
			auto finalState = finalStates[i];
			Machine machine(buttonWiredSchematics[i], finalState.size());

			auto fewestButtonPresses = findFewestButtonPresses(machine, finalState);
			totalFewestButtonPresses += fewestButtonPresses;
		}

		std::cout << "Solution day 10: " << totalFewestButtonPresses;
	}

	int findFewestButtonPresses(Machine machine, string finalState) {
		auto pressSequences = getCombinations(machine.getButtons().size());

		int fewestButtonPresses = machine.getLights().size() + 1;
		vector<int> fewestButtonSequence;
		for (auto pressSequence : pressSequences) {
			int pressesNumber = testButtonSequence(machine, pressSequence, finalState);
			
			if (pressesNumber != 0 && pressesNumber < fewestButtonPresses) {
				fewestButtonPresses = pressesNumber;
				fewestButtonSequence = pressSequence;
			}
		}

		/*std::cout << "Sequence: ";
		for (auto button : fewestButtonSequence) {
			std::cout << button;
		}
		
		std:cout << std::endl;*/


		return fewestButtonPresses;
	}

	int testButtonSequence(Machine machine, vector<int> pressSequence, string finalState) {
		int pressesNumber = 0;
		bool isFinalStateReached = false;
		for (auto buttonNumber : pressSequence) {
			machine.pressButton(buttonNumber);
			pressesNumber++;
			if (machine.getLights() == finalState) {
				isFinalStateReached = true;
				break;
			}
		}

		return isFinalStateReached ? pressesNumber : 0;
	}

	vector<vector<int>> getCombinations(int buttonsNumber) {
		vector<vector<int>> combinations;
		int totalCombinations = pow(2, buttonsNumber);
		for (int i = 0; i < totalCombinations; i++) {
			vector<int> combination;
			for (int j = 0; j < buttonsNumber; j++) {
				if (i & (1 << j)) {
					combination.push_back(j);
				}
			}
			combinations.push_back(combination);
		}
		return combinations;
	}
	
	vector<string> getFinalStatesFromFile() {
		//Get final states from file Input.txt where each state is around [] and in each line there is one state
		auto filePath = "Day10/Input.txt";
		ifstream file(filePath);
		vector<string> finalStates;
		string line;

		while (getline(file, line)) {
			//Extract state from line
			auto start = line.find('[');
			auto end = line.find(']');
			if (start != string::npos && end != string::npos) {
				auto state = line.substr(start + 1, end - start - 1);
				finalStates.push_back(state);
			}
		}

		return finalStates;
	}

	vector<vector<string>> getButtonWiredSchematicsFromFile() {
		std::ifstream file(".\\Day10\\Input.txt");
		if (!file.is_open()) {
			throw std::runtime_error("No se pudo abrir el archivo.");
		}

		std::vector<std::vector<std::string>> resultado;
		std::string linea;

		while (std::getline(file, linea)) {
			std::vector<std::string> items;
			std::string buffer;
			bool dentro = false;

			for (char c : linea) {
				if (c == '(') {
					dentro = true;
					buffer.clear();
					buffer.push_back(c);
				}
				else if (c == ')' && dentro) {
					buffer.push_back(c);
					items.push_back(buffer);
					dentro = false;
				}
				else if (dentro) {
					buffer.push_back(c);
				}
			}

			resultado.push_back(items);
		}

		return resultado;
	}
}