//
// Created by Admin on 24.02.2020.
//

#ifndef LAB2_SOURCE_H
#define LAB2_SOURCE_H

#include <vector>
#include <cstdio>

const int MAX_ARR_SIZE = 10000;

///Linked list structure
template <class T>
class Node{
    T value;
    Node* next;
    Node(T value){
        this->value = value;
        next = nullptr;
    }
};

template <class T>
class LinkedList{
private:
    Node<T>* tail;
    size_t length;

public:
    LinkedList(){
        tail->value = 0;
        tail->next = nullptr;
    }

    size_t getLength(){
        return length;
    }

};

///Class Stack
template <class T>
class Stack{
private:
    T arr[MAX_ARR_SIZE];
    std::vector<T> t;
    LinkedList<T> list;

public:
    

};

#endif //LAB2_SOURCE_H
