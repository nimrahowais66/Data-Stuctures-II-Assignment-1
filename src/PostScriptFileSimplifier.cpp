#include "../include/PostScriptFileSimplifier.hpp"

#include <string>
#include <algorithm>

#include "../include/stackPostScript.hpp"
#include "../include/utils.hpp"

PostScriptFileSimplifier::PostScriptFileSimplifier(std::string file) {
    std::ifstream File(file);

    if (!File.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
    }

    std::string line;

    while (std :: getline(File, line)) {
        fileContents.push_back(line);
    }

    File.close(); 
}

void PostScriptFileSimplifier::simplify_definitions() {
    std::unordered_map<std::string, std::string> tokens = get_tokens();
    replace_tokens(tokens);

    return;
}

void PostScriptFileSimplifier::display_file() const {
    int length = fileContents.size();

    for (int i = 0; i < length; i++){
        std :: cout << fileContents[i] << std :: endl;
    }

    return;
}

void PostScriptFileSimplifier::writefile(std::string file) const {
   std::ofstream File(file);

    if (!File.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
    }
    
    for (int i = 0; i < fileContents.size(); i++){
        File << fileContents[i] << std::endl; 
    }

    File.close();
}

void PostScriptFileSimplifier::evaluate_operations() {
    std::vector<std::string> operations = {"add", "sub", "mul", "div", "sin", "cos", "mod", "exp", "sqrt", "dup", "exch", "roll", "atan"};
    int lines = fileContents.size();
    int line_size; 
    bool operation_found;
    bool is_number;
    std::vector<std::string> split_line;
    StackPostScript stack; 
    for (int i = 0; i < lines; i++){
        operation_found = false;
        split_line = str_split(fileContents[i]);
        line_size = split_line.size();
        for (int j = 0; j < line_size; j++){
            if (std::find(operations.begin(), operations.end(), split_line[j]) != operations.end()){
                operation_found = true;
                break;        
            }
        }
        for (int k = 0; k < line_size; k++){
            is_number = false; 
            try {
                std::stold(split_line[k]);
                is_number = true;
            }
            catch (const std::invalid_argument& e) {
                is_number = false;
            }
            if (operation_found && is_number) {
                stack.push(std::stold(split_line[k]));
            }
            else if (operation_found && !is_number) {
                if (split_line[k] == "add") {
                    stack.add();
                }
                else if (split_line[k] == "sub") {
                    stack.subtract();
                }
                else if (split_line[k] == "mul") {
                    stack.multiply();
                }
                else if (split_line[k] == "div") {
                    stack.divide();
                }
                else if (split_line[k] == "sin") {
                    stack.sin();
                }
                else if (split_line[k] == "cos") {
                    stack.cos();
                }
                else if (split_line[k] == "mod") {
                    stack.mod();
                }
                else if (split_line[k] == "exp") {
                    stack.exp();
                }
                else if (split_line[k] == "sqrt") {
                    stack.sqrt();
                }
                else if (split_line[k] == "dup") {
                    stack.dup();
                }
                else if (split_line[k] == "exch") {
                    stack.exch();
                }
                else if (split_line[k] == "roll") {
                    long double j = stack.pop();
                    long double n = stack.pop();
                    stack.roll(n, j);
                }
                else if (split_line[k] == "atan") {
                    stack.atan();
                }
            }
        }
        // all operations of the line have been performed
        // now we replace the line with the items in the stack with the appropriate keywords
<<<<<<< Nimrah
        if (operation_found) {
            std::string new_line = "";
            stack.reverseStack();
            std::vector<std::string> keywords_in_line;
            for (int m = 0; m < line_size; m++){
                if (keywords.find(split_line[m]) != keywords.end()){
                    keywords_in_line.push_back(split_line[m]);
                }
            }
            for (int n = 0; n < keywords_in_line.size(); n++) {
                int num_args = keywords[keywords_in_line[n]];
                for (int p = 0; p < num_args; p++){
                    if (!stack.is_empty()) {
                        new_line += removeTrailingZeros(stack.pop()) + " ";
                    }
                }
                new_line += keywords_in_line[n] + " ";
            }
            fileContents[i] = new_line;
        }
=======
        std::string new_line = "";
        stack.reverseStack();
        std::vector<std::string> keywords_in_line;
        for (int m = 0; m < line_size; m++){
            if (std::find(keywords.begin(), keywords.end(), split_line[m]) != keywords.end()){
                keywords_in_line.push_back(split_line[m]);
            }
        }
        for (int n = 0; n < keywords_in_line.size(); n++) {
            int num_args = keywords[keywords_in_line[n]];
            for (int p = 0; p < num_args; p++){
                if (!stack.is_empty()) {
                    new_line += removeTrailingZeros(stack.pop()) + " ";
                }
            }
            new_line += keywords_in_line[n] + " ";
        }
        fileContents[i] = new_line;
>>>>>>> main
    }
}

void PostScriptFileSimplifier::replace_tokens(
    std::unordered_map<std::string, std::string>& tokens) {
    int length = fileContents.size();
    std :: vector<std :: string> lineVector;
    std :: string newLine = "";

    for (int i = 0; i < length; i++){
        lineVector = str_split(fileContents[i]);
        int lineLength = lineVector.size();

        if (lineVector[lineVector.size() -1] != "def"){

            for(int j = 0; j < lineLength; j++){
                auto pos = tokens.find(lineVector[j]);
                if(pos != tokens.end()){
                    lineVector[j] = pos->second;
                }

            }
        }

        for(int k = 0; k < lineLength; k++){
            newLine.append(lineVector[k]);
            if(k < lineLength - 2){ newLine.append(" ");}
        } 

        fileContents[i] = newLine;
    }

    return;
}

std::unordered_map<std::string, std::string> PostScriptFileSimplifier :: get_tokens() const{
    std::unordered_map<std::string, std :: string> tokensAndValues;
    std :: string token = "";
    std :: string value = "";
    int length = fileContents.size();
    std :: vector<std :: string> lineVector;

    for(int i = 0; i < length; i++){
        lineVector = str_split(fileContents[i]);
        int lineLength = lineVector.size();
        if (lineVector.back() == "def"){
            token = lineVector[0]; 
            for (int j = 1; j < lineLength - 1; j++){
                value.append(lineVector[j]);
                if (j < lineLength - 2){ value.append(" ");}
            }
            tokensAndValues.insert({token, value});
        }
    }
    
    return tokensAndValues;
}
