//
// Created by Admin on 04.02.2020.
//

#include "modes.h"
#include "functions.h"

bool interactive(Functions functions){
    bool flag = true;

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
             << "13 - delete a message\n"
             << "14 - update a message\n"
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
                functions.readingFromTxt();
                break;
            case 4:
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
                functions.generateMessages();
                break;
            case 9:
                functions.searchingBetweenTime();
                break;
            case 10:
                functions.searchingTypeAndLoading();
                break;
            case 11:
                functions.searchingSubString();
                break;
            case 12:
                functions.clearFiles();
                cout << "Files were successfully cleared :)\n";
                break;
            case 13:
                functions.deleteOneMessage();
                break;
            case 14:
                functions.updateMessage();
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

    cout << "DEMONSTRATION MODE HAS BEEN STARTED\n";
    cout << "Let's create new message\n";
    func.demoCreateNewElemAndAddToVector();
    cout << "Let's see what we have done\n";
    func.coutFromVector();
    cout << "Okay, save to txt and bin files\n";
    func.saveToFile();
    cout << "Now, we have in txt:\n";
    func.coutFromTxt();
    cout << "...and in bin:\n";
    func.coutFromBin();
    return true;
}

bool benchmark(){
    cout << "Nice\n";
}
