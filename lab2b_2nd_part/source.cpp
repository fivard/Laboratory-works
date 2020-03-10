//
// Created by Admin on 08.03.2020.
//

#include "source.h"
void MessageLog::Message::Time::outputTime() const {
    if (hour < 10)
        cout << "0";
    cout << hour;
    cout << ':';

    if (minutes < 10)
        cout << "0";
    cout << minutes;
    cout << ':';

    if (sec < 10)
        cout << "0";
    cout << sec;

    cout << ' ';

    if (day < 10)
        cout << "0";
    cout << day;
    cout << '.';

    if (month < 10)
        cout << "0";
    cout << month;
    cout << '.';

    cout << year;
}

MessageLog::Message::Message() {
    text = "";
}

MessageLog::Message::Message(string text) {
    setText(text);
    setTime();
};

MessageLog::MessageLog(int size) {
    maxSize = size;
}

void MessageLog::Message::setText(string text) {
    this->text = text;
}

void MessageLog::Message::setTime() {
    time_t seconds = time(nullptr);
    tm* timeinfo = localtime(&seconds);
    char* t_tim = asctime(timeinfo);
    string newTime = t_tim;

    string m_month = "Jan";
    m_month[0] = t_tim[4];
    m_month[1] = t_tim[5];
    m_month[2] = t_tim[6];
    string month[12] = {
            "Jan", "Feb", "Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
    };
    while(month[timeCreated.month] != m_month)
        timeCreated.month++;

    timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
    timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
    timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
    timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
    timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';
}

void MessageLog::addNewMessage(std::string message) {
    Message mess(message);

    if (log.getLength() == maxSize)
        log.pop_head();
    log.push(mess);
}

void MessageLog::generateSomeMessages(size_t count) {

    srand(time(nullptr));
    for (size_t i = 0; i < count; i++){
        string randomText;
        int length = rand()%20;
        for (int j = 0; j < length; j++)
            randomText.push_back(char(rand()%25+97));
        addNewMessage(randomText);
    }
}

void MessageLog::outputMessageLog() {
    log.printList();
}

void MessageLog::outputSomeLastElements(size_t count) {
    log.printSomeLastElements(count);
}
