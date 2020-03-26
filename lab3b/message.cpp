//
// Created by Admin on 22.03.2020.
//

#include "message.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Message::coutElem() {
    cout << this->id << '\t' << this->text
    << "\t\t" << this->timeCreated.hour << ':' << this->timeCreated.minutes << ':' << this->timeCreated.sec
    << ' ' << this->timeCreated.day << '.' << this->timeCreated.month << '.' << this->timeCreated.year
    << '\t' << this->typeOfError << "\t\t" << this->priority << "\t\t" << this->loading << ' ' << '\n' ;
}

int FullTime::moreThen(FullTime secondTime) {
    if (year > secondTime.year)
       return 1;
    else if (year < secondTime.year)
        return -1;

    if (month > secondTime.month)
        return 1;
    else if (month < secondTime.month)
        return -1;

    if (day > secondTime.day)
        return 1;
    else if (day < secondTime.day)
        return -1;

    if (hour > secondTime.hour)
        return 1;
    else if (hour < secondTime.hour)
        return -1;

    if (minutes > secondTime.minutes)
        return 1;
    else if (minutes < secondTime.minutes)
        return -1;

    if (sec > secondTime.sec)
        return 1;
    else if (sec < secondTime.sec)
        return -1;

    return 0;
}

bool Message::complicatedMoreThan(const Message &second, vector<string> comparisonFields) {
    for (auto i : comparisonFields){
        if (i == "id")
            if (this->id > second.id)
                return true;
            else if (this->id < second.id)
                return false;

        if (i == "text") {
            int textCheck = this->textMoreThan(second.text);
            if (textCheck == 1)
                return true;
            else if (textCheck == -1)
                return false;
        }

        if (i == "timeCreated") {
            int timeCreatedCheck = this->timeCreated.moreThen(second.timeCreated);
            if (timeCreatedCheck == 1)
                return true;
            else if (timeCreatedCheck == -1)
                return false;
        }

        if (i == "typeOfError") {
            int typeOfErrorCheck = this->typeOfErrorMoreThan(second.typeOfError);
            if (typeOfErrorCheck == 1)
                return true;
            else if (typeOfErrorCheck == -1)
                return false;
        }

        if (i == "priority")
            if (this->priority > second.priority)
                return true;
            else if (this->priority < second.priority)
                return false;

        if (i == "loading")
            if (this->loading > second.loading)
                return true;
            else if (this->loading < second.loading)
                return false;

    }
    return false;
}

int Message::textMoreThan(const string& second) {
    for (int i = 0; i < min(this->text.size(), second.size()); i++) {
        if (text[i] < second[i])
            return -1;
        else if (text[i] > second[i])
            return 1;
    }
    return 0;
}

int Message::typeOfErrorMoreThan(const string& second) {
    for (int i = 0; i < min(this->typeOfError.size(), second.size()); i++)
        if (typeOfError[i] < second[i])
            return -1;
        else if (typeOfError[i] > second[i])
            return 1;
    return 0;
}