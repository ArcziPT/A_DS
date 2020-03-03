//
// Created by Arek on 28.02.2020.
//

#ifndef A_DS_LINKED_LIST_H
#define A_DS_LINKED_LIST_H

template <typename DataType>
struct Linked_List{
    struct node{
        DataType data;
        node* next = nullptr;
    };

    node* head = nullptr;

    void append(DataType data);
    void remove(DataType data);
};

template<typename DataType>
void Linked_List<DataType>::append(DataType data) {
    if(head == nullptr){
        node<DataType>* n = new node<DataType>;
        n->data = data;

        head = n;
    }

    auto t = head;
    while(t->next != nullptr){
        t = t->next;
    }

    node<DataType>* n = new node<DataType>;
    n->data = data;
    t->next = n;
}

template<typename DataType>
void Linked_List<DataType>::remove(DataType data) {
    if(head == nullptr)
        return;

    auto t = head;
    auto prev = t;
    while(t->next != nullptr && t->data != data){
        prev = t;
        t = t->next;
    }

    if(t->data != data)
        return;

    prev->next = t->next;
    delete t;
}

#endif //A_DS_LINKED_LIST_H
