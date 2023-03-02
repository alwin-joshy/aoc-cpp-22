#include <iostream>
#include <sstream>

int board[3][3] = 	{{4, 1, 7},
				   	 {8, 5, 2},
				   	 {3, 9, 6}};


int victory_score(char opponent, char me) {
	return board[me][opponent];
}

int main(void) {
	std::string curr = ""; 
	int total_score = 0;
	int total_score2 = 0; 
	while(std::getline(std::cin, curr)) { 
		char a, b;
		std::stringstream iss(curr);
		iss >> a;
		iss >> b;

		a -= 'A';
		b -= 'X';
		total_score += victory_score(a, b);
		total_score2 += victory_score(a, (3 + (a + (b - 1) % 3)) % 3);
	}

	std::cout << total_score << "\n";
	std::cout << total_score2 << "\n";
}
