//
// Created by Admin on 04.02.2020.
//

#include "modes.h"
#include "functions.h"
#include <cstring>

bool interactive(Functions functions){
    bool flag = true;
    string subStr;
    string neededType;
    string newMessage;

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
             << "100 - exit\n";
        short action;
        cin >> action;
        switch (action) {
            case 1:
                functions.createNewElemAndAddToVector();
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
                functions.coutFromTxt();
                break;
            case 7:
                functions.coutFromBin();
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
                functions.searchingBetweenTime(timeBefore, timeAfter);
                break;
            case 10:
                cout << "Choose a type of message\n"
                     << "debug, info, fatal, warning, error\n";
                cin >> neededType;
                cout << "Choose a loading of message\n";
                double neededLoading;
                cin >> neededLoading;
                functions.searchingTypeAndLoading(neededType, neededLoading);
                break;
            case 11:
                cout << "Enter substring which is start of the message\n";
                cin >> subStr;
                functions.searchingSubString(subStr);
                break;
            case 12:
                functions.clearFiles();
                cout << "Files were successfully cleared :)\n";
                break;
            case 13:
                functions.log.clear();
                break;
            case 14:
                cout << "Enter id of the message which you want to delete\n";
                int idOfDeletedElement;
                cin >> idOfDeletedElement;
                functions.deleteOneMessage(idOfDeletedElement);
                break;
            case 15:
                cout << "Enter id of the message which you want to update\n";
                int idOfUpdatedElement;
                cin >> idOfUpdatedElement;
                cout << "Enter new message\n";
                cin.ignore();
                getline(cin, newMessage, '\n');
                functions.updateOneMessage(idOfUpdatedElement, newMessage);
                break;
            case 100:
                flag = false;
                break;
            default: cout << "Choose correct number\n";
        }
        cout << "Do you want to continue working? y/n\n";
        char next;
        cin >> next;
        flag = next == 'y';
    }
    cout << "Do you want to choose a mode? y/n\n";
    char next;
    cin >> next;
    flag = next == 'y';
    return flag;
};

bool demonstration(){
    Functions func;
    Functions::clearFiles();
    func.define_id();

    cout << "DEMONSTRATION MODE HAS BEEN STARTED\n";
    cout << "Let's create new message\n";
    func.demoCreateNewElemAndAddToVector();
    cout << "Let's see what we have done\n\n";
    func.coutFromVector();
    cout << "\nOkay, save to txt and bin files\n\n";
    func.saveToFile();
    cout << "Now, we have in txt:\n\n";
    func.coutFromTxt();
    cout << "\n...and in bin:\n\n";
    func.coutFromBin();
    cout << "\nIts too long, let's generate 10 messages quickly and add them to files\n";
    func.generateMessages(10);
    cout << "Now, we have in txt:\n\n";
    func.coutFromTxt();
    cout << "\nAnd our vector is empty (because we had saved first message and generation is saving messages to files)\n\n";
    cout << "Let's delete ont message. For example, 5th\n";
    func.deleteOneMessage(5);
    cout << "Now, we have in txt:\n\n";
    func.coutFromTxt();
    cout << "\nLet's update a message. For example, 7th and enter new message 'Smells like teen spirits'\n\n";
    func.updateOneMessage(7, "Smells like teen spirits");
    cout << "Now, we have in txt:\n\n";
    func.coutFromTxt();
    cout << "\nChecking for duplicate. We are going to save some messages from files to vector and then save them back to files\n\n";
    func.readingFromTxt();
    cout << "We had read messages\n";
    func.saveToFile();
    cout << "It works, don't touch it\n";
    cout << "Last part of demo: searching\n";
    cout << "\n1) searchingSubString(smells)\n\n";
    func.searchingSubString("Smells");
    cout << "\n2) searchingTypeAndLoading(warning, 0.1);\n\n";
    func.searchingTypeAndLoading("warning", 0.1);
    FullTime timeBefore, timeAfter;
    timeBefore.year = func.log[0].timeCreated.year;
    timeBefore.month = func.log[0].timeCreated.month;
    timeBefore.day = func.log[0].timeCreated.day;
    timeBefore.hour = func.log[0].timeCreated.hour;
    timeBefore.minutes = func.log[0].timeCreated.minutes;
    timeBefore.sec = func.log[0].timeCreated.sec-5;
    timeAfter.year = func.log[0].timeCreated.year;
    timeAfter.month = func.log[0].timeCreated.month;
    timeAfter.day = func.log[0].timeCreated.day;
    timeAfter.hour = func.log[0].timeCreated.hour;
    timeAfter.minutes = func.log[0].timeCreated.minutes;
    timeAfter.sec = func.log[0].timeCreated.sec+5;
    cout << "\n3) searchingBetweenTime(" << timeBefore.year << "." << timeBefore.month << "." << timeBefore.day << " "
    << timeBefore.hour << ":" << timeBefore.minutes << ":" << timeBefore.sec << ", ";
    cout << timeAfter.year << "." << timeAfter.month << "." << timeAfter.day << " "
         << timeAfter.hour << ":" << timeAfter.minutes << ":" << timeAfter.sec << ")\n\n";
    func.searchingBetweenTime(timeBefore, timeAfter);

    cout << "\nTHE END OF DEMO MOD\n";
    cout << "Do you want to choose a mode? y/n\n";
    char next;
    cin >> next;
    bool flag = next == 'y';
    return flag;
}

bool benchmark(){
    

    cout << "Do you want to choose a mode? y/n\n";
    char next;
    cin >> next;
    bool flag = next == 'y';
    return flag;
}
