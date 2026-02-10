#include "../include/stackPostScript.hpp"

StackPostScript :: StackPostScript(){
    vctrstack;
}

void StackPostScript :: reverseStack(){
    if (vctrstack.empty()){
        throw std :: runtime_error("Stack is empty!");
        return;
    }
    
    int size = vctrstack.size();
    int loop = size / 2;

    for(int i = 0; i < loop ; i++){
        long double temp = vctrstack[size - 1 - i];
        vctrstack[size - 1 - i] = vctrstack[i];
        vctrstack[i] = temp;
    }

    return;
}

void StackPostScript :: dup(){
    if (vctrstack.empty()){
        throw std :: runtime_error("Stack is empty!");
        return;
    }

    vctrstack.push_back(vctrstack.back());
    return;
}

void StackPostScript :: exch(){
    if (vctrstack.size() < 2 ){
        throw std :: runtime_error("Stack is empty!");
        return;
    }

    long double temp1 = vctrstack.back();
    vctrstack.pop_back();
    long double temp2 = vctrstack.back();
    vctrstack.pop_back();

    vctrstack.push_back(temp1);
    vctrstack.push_back(temp2);

    return;
}



void StackPostScript :: push(long double item){
    vctrstack.push_back(item);
}

long double StackPostScript :: pop(){
    if (is_empty()) {
        throw std::runtime_error("Stack underflow: Attempted to pop from an empty stack."); 
    }
    long double popped = vctrstack.back();
    vctrstack.pop_back();
    return popped;
}

long double StackPostScript :: peek(){
    if (is_empty()) {
        throw std::runtime_error("Stack underflow: Attempted to peek from an empty stack."); 
    }
    return vctrstack.back();
}

