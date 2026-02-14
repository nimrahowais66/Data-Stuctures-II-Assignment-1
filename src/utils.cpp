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
    std :: string substring;
    int length = line.length();
    char* word;
    int count = 0;
    int index = 0;

    while(line != ""){
        index  = line.find(' ');
        if(index == 0){ 
            line = line.substr(1, length - 1); 
            length--;
        }

        else if(index == -1){
            if (line[0] == '/' || line[0] == '{')
                line = line.substr(1, line.size() - 1);
            
            if (line[line.size() - 1] == '}')
                line = line.substr(0, line.size() - 1);

            output.push_back(line);
            line = "";
        }

        else{
            substring = line.substr(0, index);
            if (substring[0] == '/' || substring[0] == '{')
                substring = substring.substr(1, substring.size() - 1);
            
            if (substring[substring.size() - 1] == '}')
                substring = substring.substr(0, substring.size() - 1);
            
            output.push_back(substring); 
            line = line.substr(index, length - index); 
            length = length - index;
        }
    }

    return output;
}

// testing removeTrailingZeros
// int main() {
//     long double num = 000123.45000180000;
//     std::cout << removeTrailingZeros(123.450000) << std::endl; // Output: "123.45"
//     std::cout << removeTrailingZeros(0.000000) << std::endl;   // Output:
//     std::cout << removeTrailingZeros(100.1000000) << std::endl; // Output: "100"
//     std::cout << removeTrailingZeros(0.000001) << std::endl;   // Output: "0.000001"
//     std::cout << removeTrailingZeros(00001.000000) << std::endl; // Output: "1"
//     std::cout << removeTrailingZeros(num) << std::endl; // Output: "125.5900045"
//     return 0;
// }