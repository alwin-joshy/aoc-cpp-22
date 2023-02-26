#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>
#include <set>

/* Change start to 3 for part a */
#define START 13

int main(void) {
    std::string str = "";
    std::getline(std::cin, str);
    std::set<char> set;
    
    for (int i = START; i < str.size(); i++) {
        set.clear();
        set.insert(str.begin() + i - START, str.begin() + i + 1);
        if (set.size() == 14) {
            std::cout << i + 1 << "\n";
            break;
        }
    }   
}