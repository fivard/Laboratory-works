//
// Created by Admin on 08.03.2020.
//

#ifndef LAB2B_2ND_PART_SOURCE_H
#define LAB2B_2ND_PART_SOURCE_H

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

template <class T>
class LinkedList{
private:
    class Node {
    public:
        T value;
        Node *next;
        Node *prev;

        explicit Node(T value) {
            this->value = value;
            next = prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    size_t length;

public:
    LinkedList(){
        head = tail = nullptr;
        length = 0;
    }

    size_t getLength(){
        return length;
    }

    void push(T newElement){
        Node* node = new Node(newElement);
        if (head == nullptr){
            head = tail = node;
        }else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        length++;
    }
    void pop_head(){
        if (length == 0){
            cout << "List is already empty\n";
        }

        Node* second = head->next;
        second->prev = nullptr;
        head = second;
        length--;
    }
    void printList(){
        Node* temp = head;

        for (int i = 0; i < length; i++){
            std::cout << '\t' << temp->value << '\n';
            temp = temp->next;
        }
        cout << '\n';
    }
    void printSomeLastElements(size_t count){
        if (count == length){
            printList();
            return;
        }

        int i = 0;
        Node* temp = head;
        while (i < length - count){
            temp = temp->next;
            i++;
        }

        for (; i < length; i++){
            std::cout << '\t' << temp->value << '\n';
            temp = temp->next;
        }
        cout << '\n';
    }
};


class MessageLog{

    class Message{
    public:
        class Time{
        public:
            short year;
            short month;
            short day;
            short hour;
            short minutes;
            short sec;
            void outputTime() const;
        };

        string text;
        Time timeCreated{};
        Message();
        explicit Message(string text);

        void setText(string text);
        void setTime();
        friend std::ostream & operator<<(std::ostream& out, const Message& message){
            out << "text: " << message.text << ", time: ";
            message.timeCreated.outputTime();
            return out;
        }
    };

    LinkedList<Message> log;
    int maxSize;

public:
    explicit MessageLog(int size);

    void addNewMessage(string message);
    void generateSomeMessages(size_t count);

    void outputMessageLog();
    void outputSomeLastElements(size_t count);
};

#endif //LAB2B_2ND_PART_SOURCE_H
