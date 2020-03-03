//
// Created by Arek on 28.02.2020.
//

#ifndef A_DS_SORTING_ALGORITHMS_H
#define A_DS_SORTING_ALGORITHMS_H

#include <vector>
#include <functional>

//compareFunc(d1, d2):
//-return true if d1 > d2
//-else return false

template <typename DataType>
void bubble_sort(std::vector<DataType>& tab, std::function<bool(DataType&, DataType&)> compareFunc){
    auto swap = [&tab](int i, int j) -> void{
        int t = tab[i]; tab[i] = tab[j]; tab[j] = t;
    };

    for(int i=0; i<tab.size(); i++){
        for(int j=1; j<tab.size()-i; j++){
            if(compareFunc(tab[j-1], tab[j]))
                swap(j-1, j);
        }
    }
}

template <typename DataType>
void insertion_sort(std::vector<DataType>& tab, std::function<bool(DataType&, DataType&)> compareFunc){
    for(int i=1; i<tab.size(); i++){
        int k = i;
        int v = tab[k];
        while(k > 0 && compareFunc(tab[k-1], v)){
            tab[k] = tab[k-1];
            k--;
        }
        tab[k] = v;
    }
}

template <typename DataType>
void selection_sort(std::vector<DataType>& tab, std::function<bool(DataType&, DataType&)> compareFunc){
    auto swap = [&tab](int i, int j) -> void{
        DataType t = tab[i]; tab[i] = tab[j]; tab[j] = t;
    };

    for(int i=0; i<tab.size(); i++){
        int min_idx = i;
        for(int j=i; j<tab.size(); j++){
            if(compareFunc(tab[min_idx], tab[j]))
                min_idx = j;
        }

        swap(min_idx, i);
    }
}

void quick_sort(std::vector<int>& tab);

void merge_sort(std::vector<int>& tab);

#endif //A_DS_SORTING_ALGORITHMS_H
