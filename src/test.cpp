#include "stackPostScript.cpp"
#include "utils.cpp"

void print(StackPostScript stack){
    StackPostScript tempstack;
    while(!stack.is_empty()){
        std :: cout << stack.peek() << " " ;
        tempstack.push(stack.pop());
    }

    std :: cout << std :: endl;

    while(!tempstack.is_empty()){
        stack.push(tempstack.pop());
    }

    return;
}

int main(){
    StackPostScript myStack;
    myStack.push(0);
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    myStack.push(8);

    print(myStack);
    
    std :: cout << myStack.add() << std :: endl;
    print(myStack);

    std :: cout << myStack.atan()  << std :: endl;
    print(myStack);

    std :: cout << myStack.cos()  << std :: endl;
    print(myStack);

    std :: cout << myStack.divide()  << std :: endl; 

    myStack.dup();
    print(myStack);

    myStack.exch();
    print(myStack);

    std :: cout << myStack.exp()  << std :: endl;
    print(myStack);

    std :: cout << myStack.is_empty()  << std :: endl;
    print(myStack);

    std :: cout << myStack.mod()  << std :: endl; 
    print(myStack);

    std :: cout << myStack.multiply()  << std :: endl;
    print(myStack);

    myStack.reverseStack();
    print(myStack);

    myStack.roll(4, 3);
    print(myStack);

    myStack.roll(4, -3);
    print(myStack);

    std :: cout << myStack.sin()  << std :: endl;;
    print(myStack);

    std :: cout << myStack.sqrt()  << std :: endl;;
    print(myStack);

    std :: cout << myStack.subtract()  << std :: endl;;
    print(myStack);

    std::vector<std::string> myVector = str_split("hello       i am samia");
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;

}