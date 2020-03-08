//
// Created by Admin on 08.03.2020.
//

#include "modes.h"

void interactive(){
    int size;
    cout << "Enter max size of message log\n";
    cin >> size;

    MessageLog log(size);
    string newMessage;
    bool continued = true;

    while (continued) {
        cout << "\nChoose your action\n"
             << "1 - create new message and add to message log\n"
             << "2 - output message log\n"
             << "3 - output some last messages in message log\n"
             << "100 - exit\n";
        short action;
        cin >> action;
        switch (action) {
            case 1:
                cout << "Enter text of message\n";
                cin.ignore();
                getline(cin, newMessage, '\n');
                log.addNewMessage(newMessage);
                break;
            case 2:
                log.outputMessageLog();
                break;
            case 3:
                size_t count;
                cout << "Enter count of last messages\n";
                cin >> count;
                log.outputSomeLastElements(count);
                break;
            case 100:
                continued = false;
                break;
            default:
                cout << "Incorrect number\n";
                break;
        }
    }
}
