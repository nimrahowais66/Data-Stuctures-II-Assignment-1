#include "../include/utils.hpp"

std::string removeTrailingZeros(long double number) {
    /*
    Your implementation goes here
    */
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


