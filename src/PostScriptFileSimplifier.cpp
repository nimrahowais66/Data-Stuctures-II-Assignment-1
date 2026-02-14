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
    /*
    Your implementation goes here
    */
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
    /*
    Your implementation goes here
    */
}

std::unordered_map<std::string, std::string> PostScriptFileSimplifier :: get_tokens() const{
    
}
