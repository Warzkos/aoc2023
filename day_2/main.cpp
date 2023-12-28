#include <iostream>
#include <fstream>
#include <string>

const int max_red_cubes = 12;
const int max_green_cubes = 13;
const int max_blue_cubes = 14;

const char cube_set_separator = ';';
const char cube_separator = ',';
const char game_id_end = ':';

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int id_sum = 0;

    while(std::getline(input, line)) {
        int game_id = std::stoi(line.substr(5, line.find(game_id_end)));
        line.erase(0, line.find(game_id_end)+1);
        
        int red_cubes_count = 0;
        int green_cubes_count = 0;
        int blue_cubes_count = 0;

        for(auto it = line.begin(); it != line.end(); it++) {
            if(*it == cube_set_separator || *it == cube_separator) {
                it++;
            }
            it++;
            auto num_begin = it;
            while(*it-48 >= 0 && *it-48 <= 9){
                it++;
            }
            int cube_count = std::stoi(std::string(num_begin, it));
            it++;
            switch (*it){
                case 'r':
                    if(red_cubes_count < cube_count) {
                        red_cubes_count = cube_count;
                    }
                    it += 2;
                    break;
                case 'g':
                    if(green_cubes_count < cube_count) {
                        green_cubes_count = cube_count;
                    }
                    it += 4;
                    break;
                case 'b':
                    if(blue_cubes_count < cube_count) {
                        blue_cubes_count = cube_count;
                    }
                    it += 3;
                    break;
            }
        }

        if(red_cubes_count <= max_red_cubes && green_cubes_count <= max_green_cubes && blue_cubes_count <= max_blue_cubes) {
            id_sum += game_id;
        }
    }

    std::cout << "Sum of possible games ids: " << id_sum;

    return 0;
};