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
    MessageLog mess;file.seekg(0, ios::end);
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

    mess.text = "We has created message here\n";
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
    if (count == 0)
        cout << "We didn't save any message ;(\n";
    else
        if (count == 1)
            cout << "1 message was saved to files\n";
        else
            cout << count << " messages were saved to files\n";
    log.clear();
}
//Поиск по критериям
void Functions::searchingBetweenTime() {
    cout << "Enter data before\n"
    << "Year Month Day Hour Minutes Sec\n";
    FullTime timeBefore;
    cin >> timeBefore.year >> timeBefore.month >> timeBefore.day
    >> timeBefore.hour >> timeBefore.minutes >> timeBefore.sec;
    cout << "Enter data after\n"
         << "Year Month Day Hour Minutes Sec\n";
    FullTime timeAfter;
    cin >> timeAfter.year >> timeAfter.month >> timeAfter.day
        >> timeAfter.hour >> timeAfter.minutes >> timeAfter.sec;
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
void Functions::searchingTypeAndLoading() {
    cout << "Choose a type of message\n"
         << "debug, info, fatal, warning, error\n";
    string neededType;
    cin >> neededType;
    cout << "Choose a loading of message\n";
    double neededLoading;
    cin >> neededLoading;
    Functions funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (i.typeOfError == neededType && i.loading >= neededLoading)
            i.coutElem();
    }
}
void Functions::searchingSubString() {
    cout << "Enter substring which is start of the message\n";
    string substr;
    cin >> substr;
    Functions funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (subString(i.text, substr))
            i.coutElem();
    }
}
//Удаление
void Functions::deleteOneMessage() {
    Functions func;
    func.readingFromTxt();
    func.coutFromVector();
    cout << "Enter id of the message which you want to delete\n";
    int idOfDeletedElement;
    bool flagFound = false;
    cin >> idOfDeletedElement;
    for (int i = 0; i < func.log.size(); i++)
        if (func.log[i].id == idOfDeletedElement) {
            func.log.erase(func.log.begin() + i);
            flagFound = true;
        }
    for (int i = 0; i < log.size(); i++)
        if (log[i].id == idOfDeletedElement) {
            log.erase(log.begin() + i);
        }
    if (flagFound) {
        clearFiles();
        func.saveToFile();
        define_id();
        cout << "The message was successfully deleted\n";
    } else
        cout << "You wrote incorrect id. Try once more\n";
}
//Обновление
void Functions::updateMessage() {
    Functions func;
    func.readingFromTxt();
    func.coutFromVector();
    cout << "Enter id of the message which you want to update\n";
    int idOfUpdatedElement;
    bool flagFound = false;
    cin >> idOfUpdatedElement;
    for (int i = 0; i < func.log.size(); i++)
        if (func.log[i].id == idOfUpdatedElement) {
            flagFound = true;
            string newMessage = "";
            cout << "Enter new message\n";
            cin.ignore();
            getline(cin, newMessage, '\n');
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
    if (flagFound) {
        clearFiles();
        func.saveToFile();
        cout << "The message and time was successfully updated\n";
    } else
        cout << "You wrote incorrect id. Try once more\n";
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
void Functions::generateMessages() {
    cout << "Enter count of messages\n";
    int countOfMessages;
    cin >> countOfMessages;
    Functions function;
    for (int i = 0; i < countOfMessages; i++){
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
        mess.coutElem();
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

