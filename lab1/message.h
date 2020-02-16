//
// Created by Admin on 02.02.2020.
//

#ifndef LABOR1_MESSAGE_H
#define LABOR1_MESSAGE_H
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

class FullTime{
    public:
        short year;
        short month;
        short day;
        short hour;
        short minutes;
        short sec;

        bool moreThen(FullTime);
        void coutTime();
};

class MessageLog
{
    public:
        static int count;

        int id;
        int countWords;
        std::string text;
        FullTime timeCreated;
        std::string typeOfError;
        int priority;
        double loading;

        void coutElem();
        void saveToDisk();
};

#endif //LABOR1_MESSAGE_H
