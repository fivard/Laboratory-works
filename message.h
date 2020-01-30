#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <ctime>
#include <fstream>

class FullTime{
    int year;
    int month;
    int day;
    int hour;
    int minut;
    int sec;
};

class MessageLog
{
    public:
        int id;
        std::string text;
        FullTime timeInSec;
        std::string typeOfError;
        int priority;
        double loading;

        void saveToVector(std::vector<MessageLog>);
        void saveToTxt();
        void saveToBin();
        void readFromTxt();
        void readFromBin();
};

#endif // MESSAGE_H
