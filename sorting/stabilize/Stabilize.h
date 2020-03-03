//
// Created by Arek on 26.02.2020.
//

#ifndef A_DS_STABILIZE_H
#define A_DS_STABILIZE_H

#include <vector>
#include <functional>
#include <unordered_map>

/*
	stabilize(...) given the unstable sorting function returns the stable one which uses this algorithm to sort elements

	Input: vector of elements
	
	Firstly, elements from input with the same key are inserted into linked lists in order they appeared.
	Then we grab the first element of each one and sort them using unstable algorithm.
	After that, the representatives of each key are replaced by appropiate linked list and connected in one list.
	Lastly, we map the list into vector.
*/

template <typename DataType>
struct node{
    DataType data;
    node* next = nullptr;
};

template <typename DataType>
void append(node<DataType>* n, DataType& el){
    while(n->next != nullptr){
        n = n->next;
    }

    node<DataType>* el_n = new node<DataType>;
    el_n->data = el;
    n->next = el_n;
}

template <typename DataType, typename KeyType>
std::function<void(std::vector<DataType>&, std::function<bool(DataType&, DataType&)>)> stabilize(std::function<void(std::vector<DataType>&, std::function<bool(DataType&, DataType&)>)> unstableSortingAlorithm,
                                                      std::function<KeyType(DataType&)> getKeyFunc){
    return [unstableSortingAlorithm, getKeyFunc](std::vector<DataType>& tab, std::function<bool(DataType&, DataType&)> compareFunc) -> void {
        std::unordered_map<KeyType, node<DataType>*> map;

        //create linked list of elements with same key value
        for(auto data : tab){
            if(map.count(getKeyFunc(data)) != 0){
                append(map[getKeyFunc(data)], data);
            }else{
                node<DataType>* n = new node<DataType>;
                n->data = data;

                map[getKeyFunc(data)] = n;
            }
        }

        /*
         * create vector of representatives of each key value and sort it using unstable algorithm
         * then swap each representative with linked list associated with it. Connect lists and again
         * build vector based on this linked list
        */

        //vector of representatives
        std::vector<DataType> rep;
        for(auto r : map){
            rep.push_back(r.second->data);
        }

        //sort
        unstableSortingAlorithm(rep, compareFunc);


        //replace representative with linked list of elements with the same key value
        node<DataType>* sorted_list;
        node<DataType>* t;
        bool first = true;
        for(auto r : rep){
            if(first)
                t = sorted_list = map[getKeyFunc(r)];
            else
                t->next = map[getKeyFunc(r)];

            while(t->next != nullptr){
                t = t->next;
            }

            first = false;
        }

        //clear vector
        tab.clear();

        //map list to vector
        while(sorted_list->next != nullptr){
            tab.push_back(sorted_list->data);
            sorted_list = sorted_list->next;
        }
    };
}

#endif //A_DS_STABILIZE_H
