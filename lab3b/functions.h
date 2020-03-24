//
// Created by Admin on 22.03.2020.
//

#ifndef LAB3B_FUNCTIONS_H
#define LAB3B_FUNCTIONS_H
#include "message.h"

using namespace std;

struct benchData{
    double timeGeneratingAndSaving;
    double timeReading;
    double timeSearching;
    double memoryOfData;

};

class Functions{
public:
    vector<Message> log;
    string arrOfErrors[5] = {
            "debug",
            "info",
            "fatal",
            "warning",
            "error"
    };

    static void defineId();

    //Додавання елементів
    void createNewElemAndAddToVector(string);
    //Зберігання даних (запис даних у файл)
    void saveToFile();
    //Відновлення даних (зчитування даних з файлу);
    void readingFromTxt();
    void readingFromBin();
    //Вивід всіх збережених даних;
    static void coutFromTxt();
    static void coutFromBin();
    void coutFromVector();
    //Пошук за заданими критеріями (див. підваріанти a-c );
    static void searchingBetweenTime(FullTime, FullTime);
    static void searchingTypeAndLoading(string, double);
    static void searchingSubString(string);
    void benchSearchingWithSubstr(string);
    //Видалення елементів (додаткові бали)
    void deleteOneMessage(int);
    //Модифікація елементів (додаткові бали)
    void updateOneMessage(int, string);
    //Сортировки
    vector<string> setComparisonFields();
    void outputUnusedFields(const vector<string>& comparisonFields);
    void insertionSort(int left, int right, const vector<string>& comparisonFields);
    void comboSort(int left, int right, const int& threshold, vector<string>& comparisonFields);
    void merge(int left, int middle, int right, const vector<string>& comparisonFields);
    //Допоміжні
    int countWords(string);
    void generateMessages(int);
    static bool subString(string, string);
    void clearFiles();
    benchData forBenchmark(int);//generate N message, save to files,
    //reading from files and searching random element
};
#endif //LAB3B_FUNCTIONS_H
