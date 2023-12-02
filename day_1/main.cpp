#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

int main () {
    std::ifstream input("input.txt");
    std::string line;
    int sum = 0;
    while(std::getline(input, line)) {
        for(auto it = line.begin(); it != line.end();) {
            if(*it-48 >= 0 && *it-48 <= 9) {
                ++it;
            } else {
                line.erase(it);
            }
        }
        sum += std::stoi(std::string()+line[0]+line[line.size()-1]);
    }

    std::cout << sum;
    return 0;
}