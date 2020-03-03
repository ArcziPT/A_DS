#include <iostream>
#include "../../DS/Stack.h"

struct type{
    int v1;
    int v2;
    std::string name;
};

std::ostream& operator<<(std::ostream& io, type& t){
    io<<t.v1<<" "<<t.v2<<" "<<t.name<<std::endl;
    return io;
}

int main() {
    Stack<type> stack;

    std::cout<<stack.is_empty()<<std::endl;

    stack.push({1, 1, "name1"});
    stack.push({2, 2, "name2"});
    stack.push({3, 3, "name3"});
    stack.push({4, 4, "name4"});

    std::cout<<stack.is_empty()<<std::endl;

    std::cout<<stack.top()<<std::endl;

    stack.pop();
    stack.pop();

    std::cout<<stack.top()<<std::endl;

    return 0;
}