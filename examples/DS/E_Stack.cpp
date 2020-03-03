//
// Created by Arek on 29.02.2020.
//

#include <iostream>
#include "../../DS/Stack.h"

int E_Stack() {
    Stack<int> stack;

    std::cout<<stack.is_empty()<<std::endl;

    stack.push(14234);
    stack.push(2645453);
    stack.push(58237495);
    stack.push(12387);

    std::cout<<stack.is_empty()<<std::endl;

    std::cout<<stack.top()<<std::endl;

    stack.pop();
    stack.pop();

    std::cout<<stack.top()<<std::endl;

    return 0;
}