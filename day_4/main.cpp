#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

const int max_scratch_cards = 201;

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int score = 0;

    std::vector<int> num_of_scratch_cards(max_scratch_cards, 1);
    int counter = 0;

    while(std::getline(input, line)) { // 10, 11 first num, 37,38 last num
        std::vector<int> winning_nums;
        for(int i = 10; i<38 ; i+=3) {
            winning_nums.push_back(std::stoi(std::string{line[i], line[i+1]}));
        }
        int matches = -1;
        int temp_counter = counter;
        for(int i = 42; i<115; i+=3) {
            if(std::any_of(winning_nums.begin(), winning_nums.end(), [line, i](int winning_num){return winning_num == std::stoi(std::string{line[i], line[i+1]});})) {
                matches++;
                if(temp_counter - 1 < max_scratch_cards){
                    num_of_scratch_cards[++temp_counter]+=num_of_scratch_cards[counter];
                }
            }
        }

        counter++;

        if(matches >= 0){
            score += std::pow(2, matches);
        }
    }

    std::cout << "Part 1 score: " << score << std::endl;
    std::cout << "Part 2 total scratch cards: " << std::reduce(num_of_scratch_cards.begin(), num_of_scratch_cards.end()) << std::endl;
    return 0;
}