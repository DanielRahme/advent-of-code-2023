#include <iostream>
#include <algorithm>
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

int calculate(std::ifstream& fs)
{
    int res_1{};

    return std::stoi(two_digit);
}

    while (fs.good()) {
        std::string line{};
        fs >> line;

        auto first_digit = std::find_if(line.begin(), line.end(), 
                                        [](char character){ 
                                            return std::isdigit(character); 
                                        });
        if (first_digit == std::end(line)) continue;

        auto last_digit = std::find_if(line.rbegin(), line.rend(), 
                                       [](char character){ 
                                            return std::isdigit(character); 
                                       });

        std::string result{*first_digit};
        result += *last_digit;
        res_1 += std::stoi(result);

        // Part 2
        //
        find_words(line);
    }

    return res_1;
}

int main()
{
    std::cout << "AoC 2023: Day 1" << '\n';

    // Open input file
    std::filesystem::path inputfile{"/home/danielrahme/dev/advent-of-code-2023/src/day_01/input.txt"};
    std::ifstream fs(inputfile);
    if (!fs.is_open()) std::cout << "failed to open " << inputfile << '\n';

    int result_1 = calculate(fs);
    std::cout << "Part 1: " << result_1 << '\n';
}
