#include "../include/PostScriptFileSimplifier.hpp"

#include <string>

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
    /*
    Your implementation goes here
    */
}

void PostScriptFileSimplifier::evaluate_operations() {
    /*
    Your implementation goes here
    */
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

std::unordered_map<std::string, std::string> PostScriptFileSimplifier :: get_tokens() const{
    
}
