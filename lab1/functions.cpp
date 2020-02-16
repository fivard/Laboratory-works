//
// Created by Admin on 04.02.2020.
//

#include "functions.h"
#include <fstream>
#include <iostream>

using namespace std;

void Functions::define_id() {
    ifstream file("data.txt");
    MessageLog mess;
    bool flag = true;
    if (file.peek() == EOF){
        MessageLog::count = 0;
        return;
    }
    while(file >> mess.id >> mess.countWords && flag){
        mess.text = "";
        usedId[mess.id] = true;
        string s;
        MessageLog::count = max(MessageLog::count, mess.id+1);
        for (int i = 0; i < mess.countWords; i++)
            file >> s;
        file >> mess.timeCreated.year  >> mess.timeCreated.month
             >> mess.timeCreated.day  >> mess.timeCreated.hour  >> mess.timeCreated.minutes  >> mess.timeCreated.sec
             >> mess.typeOfError  >> mess.priority  >> mess.loading;
    }
    file.close();
}
//Вывод
void Functions::coutFromVector() {
    for (auto i : log)
        i.coutElem();
}
void Functions::coutFromTxt(){
    ifstream file("data.txt");
    string s;
    while(getline(file, s))
        cout << s << endl;
    file.close();
}
void Functions::coutFromBin() {
    ifstream file("binary.txt", ios_base::binary);
    MessageLog mess;
    file.seekg(0, ios::end);
    int end_file = file.tellg();
    file.seekg(0, ios::beg);
    while (file.tellg() != end_file){
        file.read((char *) &mess.id, sizeof(mess.id));
        file.read((char *) &mess.countWords, sizeof(mess.countWords));

        int lengthOfText;
        string temp = "1";
        file.read((char *) &lengthOfText, sizeof(lengthOfText));
        for (int i = 0; i < lengthOfText; i++) {
            file.get(temp[0]);
            mess.text += temp;
        }

        file.read((char *) &mess.timeCreated.year, sizeof(mess.timeCreated.year));
        file.read((char *) &mess.timeCreated.month, sizeof(mess.timeCreated.month));
        file.read((char *) &mess.timeCreated.day, sizeof(mess.timeCreated.day));
        file.read((char *) &mess.timeCreated.hour, sizeof(mess.timeCreated.hour));
        file.read((char *) &mess.timeCreated.minutes, sizeof(mess.timeCreated.minutes));
        file.read((char *) &mess.timeCreated.sec, sizeof(mess.timeCreated.sec)); //time

        int lengthTypeOfError;
        file.read((char *) &lengthTypeOfError, sizeof(lengthTypeOfError));
        for (int i = 0; i < lengthTypeOfError; i++) {
            file.get(temp[0]);
            mess.typeOfError += temp;
        }

        file.read((char *) &mess.priority, sizeof(mess.priority)); //priority

        file.read((char *) &mess.loading, sizeof(mess.loading)); //loading
        mess.coutElem();
        mess.text.clear();
        mess.typeOfError.clear();
    }
    file.close();
}
//Чтение
void Functions::readingFromTxt() {
    ifstream file("data.txt");
    MessageLog mess;
    while(file >> mess.id >> mess.countWords){
        mess.text = "";
        string s;
        for (int i = 0; i < mess.countWords; i++){
            file >> s;
            if (i == mess.countWords - 1)
                mess.text += s;
            else
                mess.text += s + " ";
        }
        file >> mess.timeCreated.year  >> mess.timeCreated.month
        >> mess.timeCreated.day  >> mess.timeCreated.hour  >> mess.timeCreated.minutes  >> mess.timeCreated.sec
        >> mess.typeOfError  >> mess.priority  >> mess.loading;
        log.push_back(mess);
    }
    file.close();
}
void Functions::readingFromBin(){
    ifstream file("binary.txt", ios_base::binary);
    MessageLog mess;
    file.seekg(0, ios::end);
    int end_file = file.tellg();
    file.seekg(0, ios::beg);
    while (file.tellg() != end_file){
        file.read((char *) &mess.id, sizeof(mess.id));
        file.read((char *) &mess.countWords, sizeof(mess.countWords));

        int lengthOfText;
        string temp = "1";
        file.read((char *) &lengthOfText, sizeof(lengthOfText));
        for (int i = 0; i < lengthOfText; i++) {
            file.get(temp[0]);
            mess.text += temp;
        }

        file.read((char *) &mess.timeCreated.year, sizeof(mess.timeCreated.year));
        file.read((char *) &mess.timeCreated.month, sizeof(mess.timeCreated.month));
        file.read((char *) &mess.timeCreated.day, sizeof(mess.timeCreated.day));
        file.read((char *) &mess.timeCreated.hour, sizeof(mess.timeCreated.hour));
        file.read((char *) &mess.timeCreated.minutes, sizeof(mess.timeCreated.minutes));
        file.read((char *) &mess.timeCreated.sec, sizeof(mess.timeCreated.sec)); //time

        int lengthTypeOfError;
        file.read((char *) &lengthTypeOfError, sizeof(lengthTypeOfError));
        for (int i = 0; i < lengthTypeOfError; i++) {
            file.get(temp[0]);
            mess.typeOfError += temp;
        }

        file.read((char *) &mess.priority, sizeof(mess.priority)); //priority

        file.read((char *) &mess.loading, sizeof(mess.loading)); //loading
        log.push_back(mess);

        mess.text.clear();
        mess.typeOfError.clear();
    }
    file.close();
};
//Создание
void Functions::createNewElemAndAddToVector() {
    MessageLog mess;
    Functions function;

    mess.id = MessageLog::count;
    MessageLog::count++;

    cout << "Enter text of message\n";
    cin.ignore();
    getline(cin, mess.text, '\n');
    mess.countWords = function.countWords(mess.text);

    time_t seconds = time(nullptr);
    tm* timeinfo = localtime(&seconds);
    char* t_tim = asctime(timeinfo);
    string m_month = "123";
    m_month[0] = t_tim[4];
    m_month[1] = t_tim[5];
    m_month[2] = t_tim[6];
    string month[12] = {
            "Jan", "Feb", "Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
    };
    bool flag = true;
    for (mess.timeCreated.month = 0; mess.timeCreated.month < 12 && flag; mess.timeCreated.month++)
        if (month[mess.timeCreated.month] == m_month)
            flag = false;
    mess.timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
    mess.timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
    mess.timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
    mess.timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
    mess.timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';


    mess.typeOfError = arrOfErrors[rand() % 5];

    mess.priority = (MessageLog::count * rand()) % 200;

    mess.loading = rand();
    mess.loading = mess.loading / (mess.loading + MessageLog::count * rand());

    Functions::log.push_back(mess);
}
void Functions::demoCreateNewElemAndAddToVector() {
    MessageLog mess;
    Functions function;

    mess.id = MessageLog::count;
    MessageLog::count++;

    mess.text = "We has created message here";
    mess.countWords = function.countWords(mess.text);

    time_t seconds = time(nullptr);
    tm* timeinfo = localtime(&seconds);
    char* t_tim = asctime(timeinfo);
    string m_month = "123";
    m_month[0] = t_tim[4];
    m_month[1] = t_tim[5];
    m_month[2] = t_tim[6];
    string month[12] = {
            "Jan", "Feb", "Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
    };
    bool flag = true;
    for (mess.timeCreated.month = 0; mess.timeCreated.month < 12 && flag; mess.timeCreated.month++)
        if (month[mess.timeCreated.month] == m_month)
            flag = false;
    mess.timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
    mess.timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
    mess.timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
    mess.timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
    mess.timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';


    mess.typeOfError = arrOfErrors[rand() % 5];

    mess.priority = (MessageLog::count * rand()) % 200;

    mess.loading = rand();
    mess.loading = mess.loading / (mess.loading + MessageLog::count * rand());

    Functions::log.push_back(mess);
}
//Сохранение
void Functions::saveToFile() {
    int count = 0;
    for(auto i : log) {
        if (usedId[i.id] == true){
            cout << "Message with id " << i.id << " is already saved. Skipped.\n";
            continue;
        }
        count++;
        i.saveToDisk();
        usedId[i.id] = true;
    }
    log.clear();
}
//Поиск по критериям
void Functions::searchingBetweenTime(FullTime timeBefore, FullTime timeAfter) {
    Functions funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (i.timeCreated.moreThen(timeBefore) && timeAfter.moreThen(i.timeCreated)) {
            /*cout << "Time before: ";
            timeBefore.coutTime();
            cout << "Item time:";
            i.timeCreated.coutTime();
            cout << "Time after: ";
            timeAfter.coutTime();*/
            i.coutElem();
        }
    }
}
void Functions::searchingTypeAndLoading(string neededType, double neededLoading) {
    Functions funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (i.typeOfError == neededType && i.loading >= neededLoading)
            i.coutElem();
    }
}
void Functions::searchingSubString(string subStr) {
    Functions funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (subString(i.text, subStr))
            i.coutElem();
    }
}
//Удаление
void Functions::deleteOneMessage(int id) {
    Functions func;
    func.readingFromTxt();
    for (int i = 0; i < func.log.size(); i++)
        if (func.log[i].id == id) {
            func.log.erase(func.log.begin() + i);
        }
    for (int i = 0; i < log.size(); i++)
        if (log[i].id == id) {
            log.erase(log.begin() + i);
        }
    clearFiles();
    func.saveToFile();
    define_id();
}
//Обновление
void Functions::updateOneMessage(int id, string newMessage) {
    Functions func;
    func.readingFromTxt();
    for (int i = 0; i < func.log.size(); i++)
        if (func.log[i].id == id) {

            func.log[i].text = newMessage;
            func.log[i].countWords = countWords(func.log[i].text);

            time_t seconds = time(nullptr);
            tm* timeinfo = localtime(&seconds);
            char* t_tim = asctime(timeinfo);
            string m_month = "123";
            m_month[0] = t_tim[4];
            m_month[1] = t_tim[5];
            m_month[2] = t_tim[6];
            string month[12] = {
                    "Jan", "Feb", "Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
            };
            bool flag = true;
            for (func.log[i].timeCreated.month = 0; func.log[i].timeCreated.month < 12 && flag; func.log[i].timeCreated.month++)
                if (month[func.log[i].timeCreated.month] == m_month)
                    flag = false;
            func.log[i].timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
            func.log[i].timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
            func.log[i].timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
            func.log[i].timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
            func.log[i].timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';
        }
    for (int i = 0; i < log.size(); i++)
        if (log[i].id == id) {

            log[i].text = newMessage;
            log[i].countWords = countWords(log[i].text);

            time_t seconds = time(nullptr);
            tm* timeinfo = localtime(&seconds);
            char* t_tim = asctime(timeinfo);
            string m_month = "123";
            m_month[0] = t_tim[4];
            m_month[1] = t_tim[5];
            m_month[2] = t_tim[6];
            string month[12] = {
                    "Jan", "Feb", "Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
            };
            bool flag = true;
            for (log[i].timeCreated.month = 0; log[i].timeCreated.month < 12 && flag; log[i].timeCreated.month++)
                if (month[log[i].timeCreated.month] == m_month)
                    flag = false;
            log[i].timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
            log[i].timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
            log[i].timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
            log[i].timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
            log[i].timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';
        }
    clearFiles();
    func.saveToFile();
    define_id();
}
//Вспомогательные
int Functions::countWords(string s) {
    if (s.size() == 0)
        return 0;
    int count = 0;
    for (int i = 0; i < s.size()-1; i++)
        if (s[i] == ' ' && s[i+1] != ' ')
            count++;
    if (s[s.size()] != ' ')
        count++;
    if (s[0] == ' ')
        count--;

    return count;
}
void Functions::generateMessages(int n) {
    Functions function;
    for (int i = 0; i < n; i++){
        MessageLog mess;

        mess.id = MessageLog::count;
        MessageLog::count++;

        int randCountSymblos = rand()%16+3;
        string temp = "1";
        for(int j = 0; j < randCountSymblos; j++){
            temp[0] = rand()%30+92;
            mess.text += temp;
        }

        mess.countWords = function.countWords(mess.text);

        time_t seconds = time(nullptr);
        tm* timeinfo = localtime(&seconds);
        char* t_tim = asctime(timeinfo);
        string m_month = "123";
        m_month[0] = t_tim[4];
        m_month[1] = t_tim[5];
        m_month[2] = t_tim[6];
        string month[12] = {
                "Jan", "Feb", "Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
        };
        bool flag = true;
        for (mess.timeCreated.month = 0; mess.timeCreated.month < 12 && flag; mess.timeCreated.month++)
            if (month[mess.timeCreated.month] == m_month)
                flag = false;
        mess.timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
        mess.timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
        mess.timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
        mess.timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
        mess.timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';


        mess.typeOfError = arrOfErrors[rand() % 5];

        mess.priority = (MessageLog::count * rand()) % 200;

        mess.loading = rand();
        mess.loading = mess.loading / (mess.loading + MessageLog::count * rand());

        function.log.push_back(mess);
    }
    function.saveToFile();
}
bool Functions::subString(string main, string substring){
    for (int i = 0; i < substring.size(); i++)
        if (main[i] != substring[i])
            return false;
    return true;
}
void Functions::clearFiles() {
    ofstream fileTxt("data.txt", ios::out);
    fileTxt.close();
    MessageLog::count = 0;
    for (int i = 0; i < 10000; i++)
        usedId[i] = 0;
    ofstream fileBin("binary.txt", ios::out);
    fileBin.close();
}

