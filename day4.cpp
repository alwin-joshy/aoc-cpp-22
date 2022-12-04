#include <sstream>
#include <array>
#include <iostream>
#include <vector>

bool contains(int start1, int end1, int start2, int end2) {
	if (start1 <= start2 && end1 >= end2) {
		return true; 
	} else if (start2 <= start1 && end2 >= end1) {
		return true;
	}

	return false; 
}

bool overlap(int start1, int end1, int start2, int end2) {
	if (start1 >= start2 && start1 <= end2) {
		return true;
	} else if (start2 >= start1 && start2 <= end1) {
		return true; 
	}

	return false; 
}

int main(void) {
	int i = 0;
	int sum = 0, sum2 = 0; 
	std::string curr; 
	std::vector<std::string> input;
	input.resize(100000);
	while (std::getline(std::cin, input[i]))
		i++;

	for (auto j = 0; j < i; j++) {
		int start1, end1, start2, end2;
		sscanf(input[j].c_str(), "%d-%d,%d-%d", &start1, &end1, &start2, &end2);
		if (contains(start1, end1, start2, end2)) {
			sum++;
			sum2++;
		} else if (overlap(start1, end1, start2, end2)) {
			sum2++;
 		}
 	}

	std::cout << sum << "\n";
	std::cout << sum2 << "\n";
}