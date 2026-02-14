#include "stackPostScript.cpp"
#include "utils.cpp"
#include "PostScriptFileSimplifier.cpp"
 
int main() {
    PostScriptFileSimplifier mySimplifier("../input/file-1.ps");
    mySimplifier.evaluate_operations(); 
    mySimplifier.display_file();
   
    return 0;
}