#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    std::vector<std::vector<unsigned int>> seeds;

    while(std::getline(input, line)) {
        std::istringstream iss{line};
        std::string word;
        while(std::getline(iss, word, ' ')){
            if(isdigit(word[0]) == 0){
                continue;
            }
            std::vector<unsigned int> seed;
            seed.push_back(std::stoul(word));
            seed.push_back(std::stoul(word));
            seeds.push_back(seed);
        }
        break;
    }

    bool flag = false;
    std::vector<bool> swapped(seeds.size(), false);
    while(std::getline(input, line)) {
          if(line.find("map") != std::string::npos && !flag) {
            flag = true;
            continue;
        }
        if(line.empty()){
            flag = false;
            std::fill(swapped.begin(), swapped.end(), false);
            continue;
        }
        if(flag) {
            std::istringstream iss{line};
            std::string word;

            std::vector<unsigned int> dest_source_len;
            while(std::getline(iss, word, ' ')){
                dest_source_len.push_back(std::stoul(word));
            }

            for(int i = 0; i<seeds.size(); i++) {
                if(seeds[i][1] >= dest_source_len[1] && seeds[i][1] < dest_source_len[1] + dest_source_len[2] && !swapped[i]){
                    seeds[i][1] = dest_source_len[0] + seeds[i][1] - dest_source_len[1];
                    swapped[i] = true;
                }
            }
        }

    }

    unsigned int min = seeds[0][1];
    for(auto seed : seeds) {
        if(seed[1]<min){
            min = seed[1];
        }
    }

    std::cout << min << std::endl;
}