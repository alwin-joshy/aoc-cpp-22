#include <iostream>
#include <sstream>

int selection_score(char chosen) {
	if (chosen == 0)
		return 1;
	else if (chosen == 1)
		return 2;
	else
		return 3;
}

int victory_score(char opponent, char me) {
	if (opponent == me)
		return 3;
	if ((3 + (me - opponent) % 3) % 3 == 2)
		return 0;		
	else 
		return 6;
}

int main(void) {
	std::string curr = ""; 
	int total_score = 0;
	int total_score2 = 0; 
	while(std::getline(std::cin, curr)) {
		if (curr == "") continue; 
		char a, b;
		std::stringstream iss(curr);
		iss >> a;
		iss >> b;

		a -= 'A';
		b -= 'X';

		total_score += selection_score(b) + victory_score(a, b);
		total_score2 += selection_score((3 + (a + (b - 1) % 3)) % 3) + victory_score(a, (3 + (a + (b - 1) % 3)) % 3);
	}

	std::cout << total_score << "\n";
	std::cout << total_score2 << "\n";
}
