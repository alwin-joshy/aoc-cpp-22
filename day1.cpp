#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>

template<std::size_t S>
void replace_min(std::array<int, S>& arr, int sum) {
	auto min = std::min_element(arr.begin(), arr.end());
	if (*min < sum)	
		*min = sum; 	
}

int main(void) {

	int sum = 0; 
	std::array<int, 3> max = {};
	std::string curr = "";
	
	while (std::getline(std::cin, curr)) {
		if (curr != "") {
			sum += stoi(curr);
		} else if (sum != 0){
			replace_min(max, sum);
			sum = 0; 
		}
	}
	
	replace_min(max, sum);
	
	/* Part 1 */
	std::cout << "Most loaded elf has " << *std::max_element(max.begin(), max.end()) << "\n"; 
	
	/* Part 2 */	
	std::cout << "Top 3 elves have " << std::accumulate(max.begin(), max.end(), 0)<< "\n";
}
