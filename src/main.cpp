#include "stackPostScript.cpp"
#include "utils.cpp"
#include "PostScriptFileSimplifier.cpp"

//Terminal command: g++ .\main.cpp -o test

int main() { 
    PostScriptFileSimplifier mySimplifier("../input/file-1.ps");
    mySimplifier.simplify_definitions();
    mySimplifier.evaluate_operations();
    mySimplifier.writefile("../test-output/file-1-simplified.ps");

    
    return 0; 
}
