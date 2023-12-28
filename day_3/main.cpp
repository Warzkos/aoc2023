#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int search_num_to_left (std::vector<std::vector<char>> map, int row, int col) {

    if(std::isdigit(map[row][col]) == 0) {
        return 0;
    }

    int begin = col;
    while(std::isdigit(map[row][begin]) != 0) {
        begin--;
    }
    begin++;
    
    std::string num_str;
    for(int i=begin; i<=col; i++) {
        num_str += map[row][i];
    }

    return std::stoi(num_str);
}

int search_num_to_right (std::vector<std::vector<char>> map, int row, int col) {

    if(std::isdigit(map[row][col]) == 0) {
        return 0;
    }
    
    std::string num_str;

    for(int i = 0; std::isdigit(map[row][col+i]) != 0; i++) {
        num_str += map[row][col+i];
    }

    return std::stoi(num_str);
}

int sum_adjecent_numbers(std::vector<std::vector<char>> map, int row, int col) {
    int sum = 0;
    for(int i=row-1; i<=row+1; i++) {
        if(std::isdigit(map[i][col]) == 0) {
            if(std::isdigit(map[i][col-1]) != 0) {
                sum += search_num_to_left(map, i, col-1);
            }
            if(std::isdigit(map[i][col+1]) != 0) {
                sum += search_num_to_right(map, i, col+1);
            }
        } else {
            int k = 1;
            while(std::isdigit(map[i][col+k]) != 0) {
                k++;
            }
            sum += search_num_to_left(map, i, col+k-1);
        }
    }
    return sum;
}

int main() {
    std::ifstream input("input.txt");
    std::string line;
    
    std::vector<std::vector<char>> map;
    int row_cnt = 0;

    while(std::getline(input, line)) {
        std::vector<char> row;
        for(auto c : line) {
            row.push_back(c);
        }
        map.push_back(row);
    }

    int sum_of_parts = 0;

    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[i].size(); j++) {
            if(std::isdigit(map[i][j]) == 0 && map[i][j] != '.'){
                sum_of_parts += sum_adjecent_numbers(map, i, j);
            }
        }
    }

    std::cout << sum_of_parts << std::endl;

    return 0;
}