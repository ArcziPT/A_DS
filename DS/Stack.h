//
// Created by Arek on 29.02.2020.
//

#ifndef A_DS_STACK_H
#define A_DS_STACK_H

#include <cstddef>

constexpr size_t start_sz = 1000;
constexpr int growth_rate = 2;
constexpr double max_usage_co = 0.85; //max usage coefficient

template <typename DataType>
class Stack{
public:
    Stack();
    ~Stack();

    DataType& top();
    void pop();
    void push(const DataType& d);

    bool is_empty();

private:
    size_t c_sz; //current size
    size_t s_sz; //allocated space size

    char* buf; //ptr to first byte
    char* cur; //ptr to first free slot

    void reallocate();
};

template<typename DataType>
Stack<DataType>::Stack() {
    //TODO: allocate space

    buf = new char[sizeof(DataType) * start_sz];
    cur = buf;
    s_sz = start_sz;
    c_sz = 0;
}

template<typename DataType>
void Stack<DataType>::push(const DataType &d) {
    //TODO: copy d into buffer at place pointed by cur
    new(cur) DataType {d}; //placement new
    c_sz += sizeof(DataType);
    cur += sizeof(DataType);

    //check usage coefficient
    if((double)c_sz / (double)s_sz > max_usage_co)
        reallocate();
}

template<typename DataType>
void Stack<DataType>::reallocate() {
    char* old_buf = buf;
    char* old_cur = cur;
    size_t  old_c_sz = c_sz;
    size_t old_s_sz = s_sz;

    s_sz = old_s_sz * growth_rate; //update space size
    c_sz = old_c_sz; //number of object didn't change
    buf = new char[s_sz]; //allocate more space
    cur = buf;

    //data copying
    for(DataType* i = (DataType*)old_buf; i < (DataType*)old_cur; i++){
        new(cur) DataType {*i}; //copy data with placement new

        cur = (char*)((DataType*)cur + 1); //update cur
    }

    delete[] old_buf; //delete old buffer
}

template<typename DataType>
bool Stack<DataType>::is_empty() {
    return buf == cur;
}

template<typename DataType>
void Stack<DataType>::pop() {
    if(is_empty())
        return;

    cur = (char*)((DataType*)cur - 1); //decrease cur
    c_sz--; //change update c_sz

    ((DataType*)cur)->~DataType(); //call destructor
}

template<typename DataType>
DataType &Stack<DataType>::top() {
    return *((DataType*)cur - 1); //decrease cur and return object pointed by
}

template<typename DataType>
Stack<DataType>::~Stack() {
    //call DataType destructor
    for(DataType* i = (DataType*)buf; i < (DataType*)cur; i++){
        i->~DataType(); //call destructor for every object
    }

    delete[] buf; //release space
}

#endif //A_DS_STACK_H
