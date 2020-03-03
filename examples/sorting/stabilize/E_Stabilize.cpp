//
// Created by Arek on 29.02.2020.
//

#include <iostream>
#include "../../../sorting/stabilize/Stabilize.h"
#include "../../../sorting/Sorting_Algorithms.h"

//Example of stabilizing selection_sort

struct type{
    int v1;
    int v2;
};

void print(std::vector<type>& tab){
    for(auto i : tab){
        std::cout<<i.v1<<","<<i.v2<<" ";
    }
    std::cout<<std::endl;
}

int E_Stabilize() {
    std::vector<type> tab = {{10, 1}, {3, 1}, {3, 2}, {4, 1}, {2, 1}, {8, 1}, {12, 1}, {5, 1}, {10, 2}, {3, 3}, {6, 1}, {11, 1}, {0, 1}, {2, 2}, {1, 1}, {10, 3}};

    auto getKeyFunc = [](type& t) -> int{return t.v1;};
    auto compareFunc = [](type& t1, type& t2) -> bool{ return t1.v1 > t2.v1;};
    stabilize<type, int>(selection_sort<type>, getKeyFunc)(tab, compareFunc);

    print(tab);

    return 0;
}