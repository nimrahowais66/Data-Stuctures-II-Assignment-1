#include "../include/stackPostScript.hpp"
#include <cmath>

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
    return;
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

long double StackPostScript :: add(){
    if (vctrstack.size() < 2) {
        throw std::runtime_error("Stack underflow: Not enough operands for addition."); 
    }
    long double a = pop(); 
    long double b = pop();
    long double result = b + a;
    push(result);
    return result;
}

long double StackPostScript :: subtract(){
    if (vctrstack.size() < 2) {
        throw std::runtime_error("Stack underflow: Not enough operands for subtraction."); 
    }
    long double a = pop(); 
    long double b = pop(); 
    long double result = b - a; 
    push(result); 
    return result;
}

long double StackPostScript :: multiply(){
    if (vctrstack.size() < 2) {
        throw std::runtime_error("Stack underflow: Not enough operands for multiplication."); 
    }
    long double a = pop(); 
    long double b = pop(); 
    long double result = b * a; 
    push(result);
    return result;
}

long double StackPostScript :: divide(){
    if (vctrstack.size() < 2) {
        throw std::runtime_error("Stack underflow: Not enough operands for division."); 
    }
    long double a = pop(); 
    long double b = pop(); 
    long double result = b / a; 
    push(result);
    return result;
}

long double StackPostScript :: sin(){
    if (vctrstack.size() < 1) {
        throw std::runtime_error("Stack underflow: Not enough operands for sine."); 
    }
    long double a = pop(); 
    a = a * (M_PI / 180.0);
    long double result = std::sin(a);
    push(result);
    return result;
}

long double StackPostScript :: cos(){
    if (vctrstack.size() < 1) {
        throw std::runtime_error("Stack underflow: Not enough operands for cosine."); 
    }
    long double a = pop(); 
    a = a * (M_PI / 180.0);
    long double result = std::cos(a); 
    push(result);
    return result;
}

long double StackPostScript :: atan(){ 
    if (vctrstack.size() < 1) {
        throw std::runtime_error("Stack underflow: Not enough operands for atan."); 
    }

    long double number = vctrstack.back();
    vctrstack.pop_back();
    vctrstack.push_back(1 / (1 + (number * number)));
    return vctrstack.back();

}

long double StackPostScript :: mod(){
    if (vctrstack.size() < 2) {
        throw std::runtime_error("Stack underflow: Not enough operands for modulo operation."); 
    }
    long double a = pop(); 
    long double b = pop(); 
    long double result = fmod(b, a); // fmod works for non integers as well unlike %
    push(result);
    return result;
}

long double StackPostScript :: exp(){
    if (vctrstack.size() < 2) {
        throw std::runtime_error("Stack underflow: Not enough operands for exponentiation."); 
    }
    long double a = pop(); 
    long double b = pop(); 
    long double result = std::pow(b, a); 
    push(result);
    return result;
}

long double StackPostScript :: sqrt(){
    if (vctrstack.size() < 1) {
        throw std::runtime_error("Stack underflow: Not enough operands for square root."); 
    }
    long double a = pop(); 
    if (a < 0) {
        throw std::runtime_error("Invalid input: Cannot compute square root of a negative number."); 
    }
    long double result = std::sqrt(a); 
    push(result);
    return result;
}

void StackPostScript :: roll(long double n, long double j){
    if (vctrstack.size() < n) {
        throw std::runtime_error("Stack underflow: Not enough operands for roll."); 
    } 

    int m_n = static_cast<int>(n);
    int m_j = static_cast<int>(j);
    std::deque<int> deque;
    int newRoll = m_j % m_n;

    for (int i = 0; i < m_n; i ++){
        deque.push_back(vctrstack.back());
        vctrstack.pop_back();
    }

    if (newRoll < 0){
        for (int i = newRoll; i < 0; i++){
            deque.push_back(deque.front());
            deque.pop_front();
        }
    }

    else{
        for (int i = 0; i < newRoll; i++){
            deque.push_front(deque.back());
            deque.pop_back();
        }
    }

    for (int i = 0; i < m_n; i++){
            vctrstack.push_back(deque.back());
            deque.pop_back();
    }

    return;
}