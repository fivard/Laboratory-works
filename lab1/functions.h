//
// Created by Admin on 04.02.2020.
//

#ifndef LABOR1_FUNCTIONS_H
#define LABOR1_FUNCTIONS_H
#include "message.h"

using namespace std;

class Functions{
    public:
        vector<MessageLog> log;
        static bool usedId[10000];

        string arrOfErrors[5] = {
                "debug",
                "info",
                "fatal",
                "warning",
                "error"
        };

        static void define_id();

        //Додавання елементів
        void createNewElemAndAddToVector();
        void demoCreateNewElemAndAddToVector();
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
        static void searchingBetweenTime();
        static void searchingTypeAndLoading();
        static void searchingSubString();
        //Видалення елементів (додаткові бали)
        void deleteOneMessage();
        //Модифікація елементів (додаткові бали)
        static void updateMessage();
        //Допоміжні
        static int countWords(string);
        void generateMessages();
        static bool subString(string, string);
        static void clearFiles();
};

#endif //LABOR1_FUNCTIONS_H

//addingToFile +
//addingToVector +
//readingFromTxt +
//readingFromBin +
//coutAllData +
//searching -
//checking id +