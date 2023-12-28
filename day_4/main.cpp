#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int score = 0;

    while(std::getline(input, line)) { // 10, 11 first num, 37,38 last num
        std::vector<int> winning_nums;
        for(int i = 10; i<38 ; i+=3) {
            winning_nums.push_back(std::stoi(std::string{line[i], line[i+1]}));
        }
        int matches = -1;
        for(int i = 42; i<115; i+=3) {
            if(std::any_of(winning_nums.begin(), winning_nums.end(), [line, i](int winning_num){return winning_num == std::stoi(std::string{line[i], line[i+1]});})) {
                matches++;
            }
        }

        if(matches >= 0){
            score += std::pow(2, matches);
        }
    }

    std::cout << score << std::endl;

    return 0;
}