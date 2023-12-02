#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
#include <string>
#include <string_view>
#include <sstream>
#include <cstdio>
#include <filesystem>
#include <unordered_map>
#include <ranges>

void adv_tokenizer(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        std::cout << word << std::endl;

    }
}
 

int main()
{
    // Open input file
    std::filesystem::path inputfile{"/home/danielrahme/dev/advent-of-code-2023/src/day_02/example_input.txt"};
    std::ifstream fs(inputfile);
    if (!fs.is_open()) std::cout << "failed to open " << inputfile << '\n';

    std::string line{};
    while(getline(fs, line)){ //read data from file object and put it into string.
        //std::cout << line << "\n"; //print the data of the string
        //
        //adv_tokenizer(line, ';');
        std::cout << '\n';
        auto strings = line | std::views::split(';');
        for (const auto &ref : strings) {
            // C++ 20
            std::cout << '\n' << std::string_view{ref.begin(), ref.end()};
            // C++ 23
            //std::cout << '\n' << std::string_view{ref};
        }
    }
}
