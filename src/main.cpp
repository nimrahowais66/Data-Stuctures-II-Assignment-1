#include "stackPostScript.cpp"
#include "utils.cpp"
#include "PostScriptFileSimplifier.cpp"

int main() { 
    PostScriptFileSimplifier mySimplifier("../input/file-2.eps");
    mySimplifier.display_file();
    mySimplifier.simplify_definitions();
    std :: cout << std :: endl;
    mySimplifier.display_file();

    
    return 0; 
}
