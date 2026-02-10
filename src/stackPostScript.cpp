#include "../include/stackPostScript.hpp"

StackPostScript :: StackPostScript(){
    vctrstack;
}

void StackPostScript :: reverseStack(){
    
    int size = vctrstack.size();
    int loop = size / 2;

    for(int i = 0; i < loop ; i++){
        long double temp = vctrstack[size - 1 - i];
        vctrstack[size - 1 - i] = vctrstack[i];
        vctrstack[i] = temp;
    }

    return;
}


