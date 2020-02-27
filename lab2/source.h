//
// Created by Admin on 24.02.2020.
//

#ifndef LAB2_SOURCE_H
#define LAB2_SOURCE_H

#include <vector>
#include <cstdio>
#include <iostream>

const int MAX_ARR_SIZE = 10000;

///Circle

class Circle{
private:
    class Point{
    public:
        double x, y;
        Point(){
            x = y = 0;
        }
    };

    Point point;
    double radius;

public:
    Circle(){
        point.x = point.y = radius = 0;
    }
    Circle(double newX, double newY, double newRadius) {
        point.x = newX;
        point.y = newY;
        radius = newRadius;
    }

    Point getPoint(){
        return point;
    }
    void setPoint(double newX, double newY) {
        point.x = newX;
        point.y = newY;
    }

    double getRadius(){
        return  radius;
    }
    void setRadius(double newRadius){
        radius = newRadius;
    }

    friend std::ostream & operator<<(std::ostream& out, const Circle& circle){
        out << "x = " << circle.point.x << ", y = " << circle.point.y << ", radius = " << circle.radius;
        return out;
    }

    Circle& operator=(const Circle& circle){
        if (this == &circle){
            return *this;
        }
        point.x = circle.point.x;
        point.y = circle.point.y;
        radius = circle.radius;
        return *this;
    }
    Circle& operator=(int value){
        point.x = point.y = radius = value;
        return *this;
    }
};

///Linked list

template <class T>
class LinkedList{
private:
    class Node {
    public:
        T value;
        Node *next;
        Node *prev;

        Node(T value) {
            this->value = value;
            next = prev = nullptr;
        }
    };

    Node* head;
    size_t length;

public:
    LinkedList(){
        head = nullptr;
        length = 0;
    }

    void createEmpty(){
        head = nullptr;
        length = 0;
    }

    void push(T newElement){
        Node* node = new Node(newElement);
        if (head == nullptr){
            head = node;
        }else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        length++;
    }

    void pop(){
        if (length > 0){
            head = head->next;
            length--;
        }else {
            std::cout << "List is already empty\n";
        }
    }

    T peek(){
        return head->value;
    }

    void printList(){
        Node* temp = head;
        std::cout << "LIST:\n"
                << "PEEK: ";
        if (length == 0)
            std::cout << std::endl;

        for (int i = 0; i < length; i++){
            std::cout << temp->value << '\n';
            temp = temp->next;
        }
        std::cout << "END OF THE LIST\n";
    }

    bool isEmpty(){
        return length == 0;
    }

};

/// Stack
template <class T>
class Stack{
private:
    T arr[MAX_ARR_SIZE];
    std::vector<T> vec;
    LinkedList<T> list;
    size_t insertionIndexArr;
    size_t insertionIndexVec;

public:
    Stack(){
        insertionIndexArr = 0;
        insertionIndexVec = 0;
    }
    ///create_empty
    void createEmptyArr(){
        insertionIndexArr = 0;
    }
    void createEmptyVec(){
        insertionIndexVec = 0;
    }
    void createEmptyList(){
        list.createEmpty();
    }
    ///push
    void pushToArr(T newElement){
        if (insertionIndexArr == MAX_ARR_SIZE){
            std::cout << "LIMIT OF THE ARRAY HAS BEEN REACHED\n";
            return;
        }
        arr[insertionIndexArr] = newElement;
        insertionIndexArr++;
    }
    void pushToVec(T newElement){
        vec.push_back(newElement);
        insertionIndexVec++;
    }
    void pushToList(T newElement){
        list.push(newElement);
    }
    ///pop
    void popFromArr(){
        if (isEmptyArr())
            return;
        arr[insertionIndexArr-1] = 0;
        insertionIndexArr--;
    }
    void popFromVec(){
        if (isEmptyVec())
            return;
        vec.pop_back();
        insertionIndexVec--;
    }
    void popFromList(){
        if (isEmptyList())
            return;
        list.pop();
    }
    ///peek
    T peekOfArr(){
        return arr[insertionIndexArr-1];
    }
    T peekOfVec(){
        return vec[insertionIndexVec-1];
    }
    T peekOfList(){
        return list.peek();
    }
    ///is_empty
    bool isEmptyArr(){
        return insertionIndexArr == 0;
    }
    bool isEmptyVec(){
        return insertionIndexVec == 0;
    }
    bool isEmptyList(){
        return list.isEmpty();
    }
    ///Other
    void coutArr(){
        std::cout << "ARRAY:\n"
                << "PEEK: ";
        if (insertionIndexArr == 0)
            std::cout << std::endl;

        for (int i = insertionIndexArr-1; i >= 0; i--)
            std::cout << arr[i] << std::endl;
        std::cout << "END OF THE ARRAY\n";
    }
    void coutVec(){
        std::cout << "VECTOR:\n"
                << "PEEK: ";
        if (insertionIndexVec == 0)
            std::cout << std::endl;
        for (int i = insertionIndexVec-1; i >= 0; i--)
            std::cout << vec[i] << std::endl;
        std::cout << "END OF THE VECTOR\n";
    }
    void coutList(){
        list.printList();
    }

    void generateToArr(int n){
        for (int i = 0; i < n; i++){
            T temp;
            temp = rand();
            pushToArr(temp);
        }
    }
    void generateToVec(int n){
        for (int i = 0; i < n; i++){
            T temp;
            temp = rand();
            pushToVec(temp);
        }
    }
    void generateToList(int n){
        for (int i = 0; i < n; i++){
            T temp;
            temp = rand();
            pushToList(temp);
        }
    }

};
#endif //LAB2_SOURCE_H
