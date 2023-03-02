// Day 8
#include <iostream>
#include <vector>

static std::vector<std::vector<int>> trees;

bool recurse(int i, int j, int step_i, int step_j, int val) {
	i += step_i;
	j += step_j;

	if (i < 0 || i == trees.size() || j < 0 || j == trees[0].size()) return true;

	if (trees[i][j] >= val) {
		return false;
	}

	return recurse(i, j, step_i, step_j, val);
}

int recurse2(int i, int j, int step_i, int step_j, int val) {
	i += step_i;
	j += step_j;

	if (i < 0 || i == trees.size() || j < 0 || j == trees[0].size()) return 0;

	if (trees[i][j] >= val) {
		return 1;
	}


	return 1 + recurse2(i, j, step_i, step_j, val);
}

int main(void) {
	std::string curr;

	int i = 0; 
	while (std::getline(std::cin, curr)) {
		trees.push_back(std::vector<int>());
		for (int j = 0; j < curr.length(); j++){
			trees[i].push_back((int) curr.c_str()[j] - '0');
		}
		i++;
	}

	int count = 2 * trees.size() + 2 * trees[0].size() - 4;

	/* Part 1 */
	for (int i = 1; i < trees.size() - 1; i++) {
		for (int j = 1; j < trees.size() - 1; j++) {
			if (recurse(i, j, 1, 0, trees[i][j]) || recurse(i, j, -1, 0, trees[i][j]) || recurse(i, j, 0, 1, trees[i][j]) || recurse(i, j, 0, -1, trees[i][j])) {
				count++;
			}
		}
	}

	/* Part 2*/
	int max_score = 0;
	int max_i, max_j;
	for (int i = 0; i < trees.size(); i++) {
		for (int j = 0; j < trees.size(); j++) {
			int score = recurse2(i, j, 1, 0, trees[i][j]) * recurse2(i, j, -1, 0, trees[i][j]) * recurse2(i, j, 0, 1, trees[i][j]) * recurse2(i, j, 0, -1, trees[i][j]);
			if (score > max_score) {
				max_i = i;
				max_j = j;
				max_score = score;
			}
			
		}
	}

	/* Part 1*/
	std::cout << count << "\n";

	/* Part 2 */
	std::cout << max_i << " " << max_j << " " << max_score << "\n";



}