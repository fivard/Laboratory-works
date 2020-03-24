//
// Created by Admin on 22.03.2020.
//

#ifndef LAB3B_MESSAGE_H
#define LAB3B_MESSAGE_H
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class FullTime{
public:
    short year;
    short month;
    short day;
    short hour;
    short minutes;
    short sec;

    int moreThen(FullTime);
};

class Message
{
public:
    static int count;

    int id;
    int countWords;
    string text;
    FullTime timeCreated;
    string typeOfError;
    int priority;
    double loading;
    bool savedInFiles;

    void coutElem();
    bool complicatedMoreThan(const Message&second, vector<string> comparisonFields);
    int textMoreThan(const string& second);
    int typeOfErrorMoreThan(const string& second);
};
#endif //LAB3B_MESSAGE_H
