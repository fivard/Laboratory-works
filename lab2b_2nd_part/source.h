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
            void outputTime();
        };

        string text;
        Time timeCreated{};
        explicit Message(string text);

        void setText(string text);
        void setTime();
        void output();
    };

    vector<Message> log;
    int maxSize;

public:
    explicit MessageLog(int size);
    void addNewMessage(string message);
    void outputMessageLog();
    void outputSomeLastElements(size_t count);
};

#endif //LAB2B_2ND_PART_SOURCE_H
