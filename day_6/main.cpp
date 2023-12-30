#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    std::vector<std::vector<int>> times_distances;

    while(std::getline(input, line)) {
        std::istringstream iss{line};
        std::string word;
        std::vector<int> values;
        while(std::getline(iss, word, ' ')){
            if(isdigit(word[0]) == 0){
                continue;
            }
            values.push_back(std::stoi(word));
        }
        times_distances.push_back(values);
    }

    int wins = 0;

    for(int i = 0; i<times_distances[0].size(); i++){
        int temp_wins = 0;
        for(int j = 0; j<times_distances[0][i]; j++){
            int distance = j*(times_distances[0][i]-j);
            if(distance > times_distances[1][i]){
                temp_wins++;
            }
        }
        if(wins == 0){
            wins = temp_wins;
        } else {
            wins *= temp_wins;
        }
    }

    std::cout << "Score: " << wins << std::endl;
}