#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>

int prio(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 1;
	} else {
		return c - 'A' + 27;
	}
}


int main(void) {
	int i = 0;
	std::string curr; 
	std::array<std::string, 1000> input;
	while (std::getline(std::cin, input[i]))
		i++;

	/* Part 1*/
	int sum = 0;
	for (auto str : input) {
		auto comp1 = str.substr(0, str.length() / 2);
		auto comp2 = str.substr(str.length() / 2);

		for (auto j = comp1.cbegin(); j != comp1.cend(); j++) {
			if (comp2.find(*j) != std::string::npos) {
				sum += prio(*j);
				break;
			}
		}
	}

	std::cout << sum << "\n";

	/* Part 2 */
	int sum2 = 0;
	for (int i = 0; i < input.size(); i += 3) {
		for (auto j = input[i].begin(); j != input[i].end(); j++) {
			if (input[i+1].find(*j) != std::string::npos && input[i+2].find(*j) != std::string::npos) {
				sum2 += prio(*j);
				break; 
			}
		}
	}

	std::cout << sum2 << "\n";
}