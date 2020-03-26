//
// Created by Admin on 22.03.2020.
//

#include "modes.h"
#include "functions.h"

void interactive(){
    MessageLog functions;
    functions.defineId();
    functions.log.clear();

    bool flag = true;
    string subStr;
    string neededType;
    string updatedMessage;
    string newMessage;
    vector<string> comparisonFields;

    while (flag) {
        cout << "Choose your action\n"
             << "1 - create new message and add to vector\n"
             << "2 - save all vector to txt and bin files\n"
             << "3 - reading from txt to vector\n"
             << "4 - reading from bin to vector\n"
             << "5 - show vector\n"
             << "6 - show txt\n"
             << "7 - show bin\n"
             << "8 - generate N messages to files\n"
             << "9 - searching message between 2 dates\n"
             << "10 - searching message with type and loading\n"
             << "11 - searching some message with substring which is the start of the message\n"
             << "12 - clear txt and bin files\n"
             << "13 - clear the vector\n"
             << "14 - delete a message\n"
             << "15 - update a message\n"
             << "16 - sort vector by some fields\n"
             << "17 - sort vector by typeOfError (counting Sort)\n"
             << "18 - sort vector by priority (radix Sort)\n"
             << "100 - exit\n";
        short action;
        cin >> action;
        switch (action) {
            case 1:
                cout << "Enter text of message\n";
                cin.ignore();
                getline(cin, newMessage, '\n');
                functions.createNewElemAndAddToVector(newMessage);
                break;
            case 2:
                functions.saveToFile();
                break;
            case 3:
                if (!functions.log.empty()){
                    cout << "Vector has " << functions.log.size() << " element\n"
                         << "Do you want to save them to files(1) or clear the vector(2)? Enter 1 or 2\n";
                    int action2;
                    cin >> action2;
                    switch (action2){
                        case 1:
                            functions.saveToFile();
                            functions.readingFromTxt();
                            break;
                        case 2:
                            functions.log.clear();
                            functions.readingFromTxt();
                    }
                } else
                    functions.readingFromTxt();
                break;
            case 4:
                if (!functions.log.empty()){
                    cout << "Vector has " << functions.log.size() << " element\n"
                         << "Do you want to save them to files(1) or clear the vector(2)? Enter 1 or 2\n";
                    int action2;
                    cin >> action2;
                    switch (action2){
                        case 1:
                            functions.saveToFile();
                            functions.readingFromBin();
                            break;
                        case 2:
                            functions.log.clear();
                            functions.readingFromBin();
                    }
                } else
                    functions.readingFromBin();
                break;
            case 5:
                functions.coutFromVector();
                break;
            case 6:
                MessageLog::coutFromTxt();
                break;
            case 7:
                MessageLog::coutFromBin();
                break;
            case 8:
                cout << "Enter count of messages\n";
                int countOfMessages;
                cin >> countOfMessages;
                functions.generateMessages(countOfMessages);
                break;
            case 9:
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
                MessageLog::searchingBetweenTime(timeBefore, timeAfter);
                break;
            case 10:
                cout << "Choose a type of message\n"
                     << "debug, info, fatal, warning, error\n";
                cin >> neededType;
                cout << "Choose a loading of message\n";
                double neededLoading;
                cin >> neededLoading;
                MessageLog::searchingTypeAndLoading(neededType, neededLoading);
                break;
            case 11:
                cout << "Enter substring which is start of the message\n";
                cin >> subStr;
                MessageLog::searchingSubString(subStr);
                break;
            case 12:
                functions.clearFiles();
                cout << "Files were successfully cleared :)\n";
                break;
            case 13:
                functions.log.clear();
                break;
            case 14:
                functions.coutFromTxt();
                cout << "Enter id of the message which you want to delete\n";
                int idOfDeletedElement;
                cin >> idOfDeletedElement;
                functions.deleteOneMessage(idOfDeletedElement);
                break;
            case 15:
                functions.coutFromTxt();
                cout << "Enter id of the message which you want to update\n";
                int idOfUpdatedElement;
                cin >> idOfUpdatedElement;
                cout << "Enter new message\n";
                cin.ignore();
                getline(cin, newMessage, '\n');
                functions.updateOneMessage(idOfUpdatedElement, newMessage);
                break;
            case 16:
                comparisonFields = functions.setComparisonFields();
                functions.comboSort(0, functions.log.size()-1, 50, comparisonFields);
                cout << "Sorted\n";
                break;
            case 17:
                functions.countingSortByTypeOfError();
                cout << "Sorted\n";
                break;
            case 18:
                functions.radixSortByPriority();
                cout << "Sorted\n";
                break;
            case 100:
                flag = false;
                break;
            default: cout << "Choose correct number\n";
        }
    }
};

void demonstration(){
    MessageLog func;
    func.clearFiles();
    MessageLog::defineId();
    int size = 30;

    cout << "Generate " << size << " random mess\n";
    func.generateMessages(size);
    func.coutFromVector();

    string firstField = "priority";
    string secondField = "loading";
    vector<string> comparisonFields;
    comparisonFields.push_back(firstField);
    comparisonFields.push_back(secondField);
    cout << "\nSort by " << firstField << " and " << secondField << " with comboSort\n";
    func.comboSort(0, size-1, 5, comparisonFields);
    func.coutFromVector();

    cout << "\nSort by typeOfError with countingSort\n";
    func.countingSortByTypeOfError();
    func.coutFromVector();

    cout << "\nSort by priority with radixSort\n";
    func.radixSortByPriority();
    func.coutFromVector();

    cout << "\nTHE END OF DEMO MOD\n";
}

void benchmark(){
    MessageLog workingLog, buffer;
    int size = 10000;
    workingLog.generateMessages(size);
    workingLog.copyTo(buffer);
    cout << "Generate log with " << size << " elements\n";

    cout << "Sort by typeOfError. ComboSort and CountingSort\n";
    vector<string> comparisonFields = {"typeOfError"};
    cout << "ComboSort's time = " << timeComboSort(workingLog, comparisonFields) << endl;
    buffer.copyTo(workingLog);
    cout << "CountingSort's time = " << timeCountingSort(workingLog) << endl;
    buffer.copyTo(workingLog);

    cout << "\nSort by priority. ComboSort and RadixSort\n";
    comparisonFields = {"priority"};
    cout << "ComboSort's time = " << timeComboSort(workingLog, comparisonFields) << endl;
    buffer.copyTo(workingLog);
    cout << "RadixSort's time = " << timeRadixSort(workingLog) << endl;
    buffer.copyTo(workingLog);

    cout << "\nSort by typeOfError and loading. ComboSort and CountingSort. CountingSort is sorting only by typeOfError\n";
    comparisonFields = {"typeOfError", "loading"};
    cout << "ComboSort's time = " << timeComboSort(workingLog, comparisonFields) << endl;
    buffer.copyTo(workingLog);
    cout << "CountingSort's time = " << timeCountingSort(workingLog) << endl;
    buffer.copyTo(workingLog);

    cout << "\nSort by priority and id. ComboSort and RadixSort. RadixSort is sorting only by priority\n";
    comparisonFields = {"priority", "id"};
    cout << "ComboSort's time = " << timeComboSort(workingLog, comparisonFields) << endl;
    buffer.copyTo(workingLog);
    cout << "RadixSort's time = " << timeRadixSort(workingLog) << endl;
    buffer.copyTo(workingLog);

    cout << "\nTHE END OF BENCHMARK MOD\n";
}

double timeComboSort(MessageLog workingLog, vector<string> comparisonFields){
    double startComboSort = clock();
    workingLog.comboSort(0, workingLog.log.size()-1, 50, comparisonFields);
    double endComboSort = clock();
    double timeComboSort = (endComboSort - startComboSort) / CLOCKS_PER_SEC;
    return timeComboSort;
}

double timeCountingSort(MessageLog workingLog){
    double startCountingSort = clock();
    workingLog.countingSortByTypeOfError();
    double endCountingSort = clock();
    double timeCountingSort = (endCountingSort - startCountingSort) / CLOCKS_PER_SEC;
    return timeCountingSort;
}

double timeRadixSort(MessageLog workingLog){
    double startRadixSort = clock();
    workingLog.radixSortByPriority();
    double endRadixSort= clock();
    double timeRadixSort = (endRadixSort - startRadixSort) / CLOCKS_PER_SEC;
    return timeRadixSort;
}

