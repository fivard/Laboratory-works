//
// Created by Admin on 22.03.2020.
//

#include "functions.h"
#include <fstream>
#include <iostream>

using namespace std;

void MessageLog::defineId() {
    ifstream file("data.txt");
    Message mess;
    bool flag = true;
    if (file.peek() == EOF){
        Message::count = 0;
        return;
    }
    while(file >> mess.id >> mess.countWords && true){
        mess.text = "";
        string s;
        Message::count = max(Message::count, mess.id+1);
        for (int i = 0; i < mess.countWords; i++)
            file >> s;
        file >> mess.timeCreated.year  >> mess.timeCreated.month
             >> mess.timeCreated.day  >> mess.timeCreated.hour  >> mess.timeCreated.minutes  >> mess.timeCreated.sec
             >> mess.typeOfError  >> mess.priority  >> mess.loading;
    }
    file.close();
}
//Вывод
void MessageLog::coutFromVector() {
    cout << "id\ttext\t\ttimeCreated\t\ttypeOfError\tpriority\tloading\n";
    for (auto i : log)
        i.coutElem();
}
void MessageLog::coutFromTxt(){
    ifstream file("data.txt");
    string s;
    while(getline(file, s))
        cout << s << endl;
    file.close();
}
void MessageLog::coutFromBin() {
    ifstream file("binary.txt", ios_base::binary);
    Message mess;
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
void MessageLog::readingFromTxt() {
    ifstream file("data.txt");
    Message mess;
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
        mess.savedInFiles = true;

        log.push_back(mess);
    }
    file.close();
}
void MessageLog::readingFromBin(){
    ifstream file("binary.txt", ios_base::binary);
    Message mess;
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
        mess.savedInFiles = true;
        log.push_back(mess);

        mess.text.clear();
        mess.typeOfError.clear();
    }
    file.close();
};
//Создание
void MessageLog::createNewElemAndAddToVector(string message) {
    Message mess;
    MessageLog function;

    mess.id = Message::count++;

    mess.text = message;
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

    mess.priority = rand() % 200;

    mess.loading = rand();
    mess.loading = mess.loading / (mess.loading + rand());

    mess.savedInFiles = false;

    MessageLog::log.push_back(mess);
}
//Сохранение
void MessageLog::saveToFile() {
    ofstream file("data.txt", ios_base::app);
    ofstream bin("binary.txt", ios_base::binary|ios_base::app);
    if (!file){
        cout << "txt is closed \n";
        return;
    }
    if (!bin){
        cout << "bin is closed \n";
        return;
    }
    for(auto & i : log) {
        if (i.savedInFiles) {
            cout << "Element with id " << i.id << " is already saved. Skipped.\n";
            continue;
        }
        i.savedInFiles = true;

        file << i.id << ' ' << i.countWords << ' ' << i.text << ' ' << i.timeCreated.year << ' ' << i.timeCreated.month
             << ' ' << i.timeCreated.day << ' ' << i.timeCreated.hour << ' ' << i.timeCreated.minutes << ' ' << i.timeCreated.sec
             << ' ' << i.typeOfError << ' ' << i.priority << ' ' << i.loading << '\n' ;

        bin.write((char*)&i.id, sizeof(i.id)); //id

        int lengthText = i.text.size();
        bin.write((char*)&i.countWords, sizeof(i.countWords));
        bin.write((char*)&lengthText, sizeof(lengthText));
        bin << i.text; //text

        bin.write((char*)&i.timeCreated.year, sizeof(i.timeCreated.year));
        bin.write((char*)&i.timeCreated.month, sizeof(i.timeCreated.month));
        bin.write((char*)&i.timeCreated.day, sizeof(i.timeCreated.day));
        bin.write((char*)&i.timeCreated.hour, sizeof(i.timeCreated.hour));
        bin.write((char*)&i.timeCreated.minutes, sizeof(i.timeCreated.minutes));
        bin.write((char*)&i.timeCreated.sec, sizeof(i.timeCreated.sec)); //time

        int lengthTypeOfError = i.typeOfError.size();
        bin.write((char*)&lengthTypeOfError, sizeof(lengthTypeOfError));
        bin << i.typeOfError; //typeOfError

        bin.write((char*)&i.priority, sizeof(i.priority)); //priority

        bin.write((char*)&i.loading, sizeof(i.loading)); //loading
    }
    file.close();
    bin.close();
}
//Поиск по критериям
void MessageLog::searchingBetweenTime(FullTime timeBefore, FullTime timeAfter) {
    MessageLog funct;
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
void MessageLog::searchingTypeAndLoading(string neededType, double neededLoading) {
    MessageLog funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (i.typeOfError == neededType && i.loading >= neededLoading)
            i.coutElem();
    }
}
void MessageLog::searchingSubString(string subStr) {
    MessageLog funct;
    funct.readingFromTxt();
    for (auto i : funct.log){
        if (subString(i.text, subStr))
            i.coutElem();
    }
}
void MessageLog::benchSearchingWithSubstr(string subStr) {
    for (auto i : log){
        if (subString(i.text, subStr))
            cout << "Element has found: " << endl, i.coutElem();
    }
}
//Удаление
void MessageLog::deleteOneMessage(int id) {
    MessageLog func;
    func.readingFromTxt();
    for (int i = 0; i < func.log.size(); i++)
        if (func.log[i].id == id) {
            func.log.erase(func.log.begin() + i);
        }
    for (int i = 0; i < log.size(); i++)
        if (log[i].id == id) {
            log.erase(log.begin() + i);
        }
    func.clearFiles();
    func.saveToFile();
    defineId();
}
//Обновление
void MessageLog::updateOneMessage(int id, string newMessage) {
    MessageLog func;
    func.readingFromTxt();
    for (auto & i : func.log)
        if (i.id == id) {

            i.text = newMessage;
            i.countWords = countWords(i.text);

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
            for (i.timeCreated.month = 0; i.timeCreated.month < 12 && flag; i.timeCreated.month++)
                if (month[i.timeCreated.month] == m_month)
                    flag = false;
            i.timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
            i.timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
            i.timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
            i.timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
            i.timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';
        }
    for (auto & i : log)
        if (i.id == id) {

            i.text = newMessage;
            i.countWords = countWords(i.text);

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
            for (i.timeCreated.month = 0; i.timeCreated.month < 12 && flag; i.timeCreated.month++)
                if (month[i.timeCreated.month] == m_month)
                    flag = false;
            i.timeCreated.day= (t_tim[8]-'0')*10+t_tim[9]-'0';
            i.timeCreated.hour = (t_tim[11]-'0')*10+t_tim[12]-'0';
            i.timeCreated.minutes = (t_tim[14]-'0')*10+t_tim[15]-'0';
            i.timeCreated.sec = (t_tim[17]-'0')*10+t_tim[18]-'0';
            i.timeCreated.year = (t_tim[20]-'0')*1000+(t_tim[21]-'0')*100+(t_tim[22]-'0')*10+t_tim[23]-'0';
        }
    func.clearFiles();
    func.saveToFile();
    defineId();
}
//Сортировки
vector<string> MessageLog::setComparisonFields() {
    vector<string> comparisonFields;

    bool continued = true;
    while (continued){
        cout << "Enter a number of a field you want to sort by\n";
        outputUnusedFields(comparisonFields);
        cout << "100 - END OF CHOOSE FIELDS\n";
        int fields;
        cin >> fields;
        switch (fields){
            case 1:
                comparisonFields.push_back("id");
                break;
            case 2:
                comparisonFields.push_back("text");
                break;
            case 3:
                comparisonFields.push_back("timeCreated");
                break;
            case 4:
                comparisonFields.push_back("typeOfError");
                break;
            case 5:
                comparisonFields.push_back("priority");
                break;
            case 6:
                comparisonFields.push_back("loading");
                break;
            case 100:
                continued = false;
                break;
            default:
                cout << "Wrong number\n";
        }
    }
    cout << "You have choosen:\n";
    for (auto i : comparisonFields)
        cout << '\t' << i << endl;
    cout << endl;
    return comparisonFields;
}
void MessageLog::outputUnusedFields(const vector<string>& comparisonFields) {
    vector<string> temp{"id", "text", "timeCreated", "typeOfError", "priority", "loading"};
    int number = 1;
    if (comparisonFields.empty())
        for (auto i : temp){
            cout << number << " - " << i<< endl;
            number++;
        }

    for (const auto& i : temp){
        int count = 0;
        for (const auto& j : comparisonFields) {
            if (i != j){
                count++;
                if (count == comparisonFields.size())
                    cout << number << " - " << i<< endl;
            }
        }
        count = 0;
        number++;
    }
}
void MessageLog::insertionSort(int left, int right, const vector<string> &comparisonFields) {
    Message tempValue;
    for (int i = left+1; i < right+1; i++){
        tempValue = log[i];
        int j = i-1;
        while (j >= left && !tempValue.complicatedMoreThan(log[j], comparisonFields)){
            log[j+1] = log[j];
            j--;
        }
        log[j+1] = tempValue;
    }
}
void MessageLog::comboSort(int left, int right, const int &threshold, vector<string> &comparisonFields) {
    if (left < right)
    {
        if (right-left <= threshold){
            insertionSort(left, right, comparisonFields);
        }
        else {
            int middle = (left + right) / 2;

            comboSort(left, middle, threshold, comparisonFields);
            comboSort(middle + 1, right, threshold, comparisonFields);

            merge(left, middle, right, comparisonFields);
        }
    }
}
void MessageLog::merge(int left, int middle, int right, const vector<string>& comparisonFields) {
    int i, j, k;
    int size1 = middle - left + 1;
    int size2 = right - middle;

    Message L[size1], R[size2];

    for (i = 0; i < size1; i++)
        L[i] = log[left + i];
    for (j = 0; j < size2; j++)
        R[j] = log[middle + 1+ j];

    i = j = 0;
    k = left;
    while (i < size1 && j < size2){
        if (!L[i].complicatedMoreThan(R[j], comparisonFields))
            log[k] = L[i++];
        else
            log[k] = R[j++];
        k++;
    }
    while (i < size1)
        log[k++] = L[i++];

    while (j < size2)
        log[k++] = R[j++];
}
void MessageLog::countingSortByTypeOfError() {
    map<string, int> count;

    for (const auto& i : log){
        count[i.typeOfError]++;
    }
    for (auto i = ++count.begin(); i != count.end(); i++){
        auto previous = --i;
        i++;
        i->second += previous->second;
    }

    auto* tempLog = new Message [log.size()];

    for (int i = log.size()-1; i >= 0; i--){
        int newIndex = count[log[i].typeOfError];
        tempLog[newIndex-1] = log[i];
        count[log[i].typeOfError]--;
    }

    for (int i = 0; i < log.size(); i++)
        log[i] = tempLog[i];

    delete [] tempLog;
}
void MessageLog::radixSortByPriority() {
    for (int i = 1; i <= 100; i *= 10)
        countingSortForRadixSort(i);
}
void MessageLog::countingSortForRadixSort(int exp) {
    int count[10] = {0};
    Message* tempLog = new Message [log.size()];

    for (auto i : log)
        count[(i.priority/exp)%10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = log.size()-1; i >= 0; i--){
        int newIndex = count[(log[i].priority/exp)%10];
        tempLog[newIndex - 1] = log[i];
        count[(log[i].priority/exp)%10]--;
    }

    for (int i = 0; i < log.size(); i++)
        log[i] = tempLog[i];

    delete [] tempLog;
}
//Вспомогательные
int MessageLog::countWords(string s) {
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
void MessageLog::generateMessages(int n) {
    srand(time(nullptr));

    for (int i = 0; i < n; i++){
        Message mess;

        mess.id = Message::count++;

        int randCountSymblos = rand()%5+3;
        string temp = "1";
        for(int j = 0; j < randCountSymblos; j++){
            temp[0] = rand()%30+92;
            mess.text += temp;
        }

        mess.countWords = countWords(mess.text);

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

        mess.priority = (Message::count * rand()) % 200;

        mess.loading = rand();
        mess.loading = mess.loading / (mess.loading + Message::count * rand());
        mess.savedInFiles = false;

        log.push_back(mess);
    }
    saveToFile();
}
bool MessageLog::subString(string main, string substring){
    for (int i = 0; i < substring.size(); i++)
        if (main[i] != substring[i])
            return false;
    return true;
}
void MessageLog::clearFiles() {
    ofstream fileTxt("data.txt", ios::out);
    fileTxt.close();
    ofstream fileBin("binary.txt", ios::out);
    fileBin.close();
    if (log.size() == 0)
        Message::count = 0;
    else
        for (auto & i : log){
            i.savedInFiles = false;
            Message::count = max(Message::count, i.id);
        }
}
void MessageLog::copyTo(MessageLog buffer) {
    buffer.log.clear();
    for (auto i : log)
        buffer.log.push_back(i);
}
