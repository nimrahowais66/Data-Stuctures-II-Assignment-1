#include "../include/utils.hpp"

#include <iostream>

std::string removeTrailingZeros(long double number) {
    std::string s = std::to_string(number);
    size_t decimal_pos = s.find('.');
    bool decimal_found = false;
    if (decimal_pos != std::string::npos) {
        decimal_found = true;
    }
    while (s[0] == '0' || s[s.length() - 1] == '0') {
        if (s[0] == '0') {
            s.erase(0, 1);
        }
        if (s[s.length() - 1] == '0' && decimal_found) {
            s.pop_back();
        }
    }
    if (s.length() == 1 && s[0] == '.') {
        s = "0";
    }
     if (s.length() == 0) {
        s = "0";
    }
     if (s[0] == '.' && s.length() > 1) {
        s = "0" + s;
    }
     if (s[s.length() - 1] == '.' && s.length() > 1) {
        s.pop_back();
    }
    return s;
}

std::vector<std::string> str_split(std::string line) {
    std::vector<std::string> output;
    int length = line.length();
    int start = 0;
    int count = 0;

    for(int i = 0; i < length; i++){
        if (line[0] == ' '){ start = 1; }
        else{
            if (line[i] == ' ' || i == length - 1){
                output.push_back(line.substr(start, count));
                start = i + 1;
                count = 0;
            } 
            else{
                count++;
            }
        }
    }

    return output;
}

// testing removeTrailingZeros
int main() {
    long double num = 000123.45000180000;
    std::cout << removeTrailingZeros(123.450000) << std::endl; // Output: "123.45"
    std::cout << removeTrailingZeros(0.000000) << std::endl;   // Output:
    std::cout << removeTrailingZeros(100.1000000) << std::endl; // Output: "100"
    std::cout << removeTrailingZeros(0.000001) << std::endl;   // Output: "0.000001"
    std::cout << removeTrailingZeros(00001.000000) << std::endl; // Output: "1"
    std::cout << removeTrailingZeros(num) << std::endl; // Output: "125.5900045"
    return 0;
}