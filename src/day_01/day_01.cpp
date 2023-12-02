#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <sstream>
#include <cstdio>
#include <filesystem>

int parse_number_from_string(const std::string_view& line)
{
    std::string number = "";
    for (auto character : line) {
        if (std::isdigit(character)) {
            number += character;
        }
    }
    if (number.empty()) return 0;
    std::string two_digit{number.front()};

    two_digit += number.size() > 1 
                ? number.back() 
                : number.front();

    return std::stoi(two_digit);
}

int part1(std::ifstream& fs)
{
    int sum = 0;
    while (fs.good()) {
        std::string line{};
        fs >> line;
        sum += parse_number_from_string(line);
    }
    return sum;
}

int main()
{
    std::cout << "AoC 2023: Day 1" << '\n';

    // Open input file
    std::filesystem::path inputfile{"/home/danielrahme/dev/advent-of-code-2023/src/day_01/input.txt"};
    std::ifstream fs(inputfile);
    if (!fs.is_open()) std::cout << "failed to open " << inputfile << '\n';

    auto result_1 = part1(fs);
    std::cout << "Part 1: " << result_1 << '\n';
}
