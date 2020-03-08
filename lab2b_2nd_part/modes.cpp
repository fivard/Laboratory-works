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
             << "2 - generate some random messages to message log\n"
             << "3 - output message log\n"
             << "4 - output some last messages in message log\n"
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
                int countOfRandomMessages;
                cout << "Enter count of messages\n";
                cin >> countOfRandomMessages;
                log.generateSomeMessages(countOfRandomMessages);
                break;
            case 3:
                log.outputMessageLog();
                break;
            case 4:
                size_t countOfOutputMessages;
                cout << "Enter count of last messages\n";
                cin >> countOfOutputMessages;
                log.outputSomeLastElements(countOfOutputMessages);
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

void demonstration(){
    cout << "Creating message log with max size 10\n\n";
    MessageLog log(10);

    cout << "Adding new message \"1st message\"\n\n";
    log.addNewMessage("1st message");

    cout << "Output log\n\n";
    log.outputMessageLog();

    cout << "Generate 10 random messages to message log."
    << " First message will be deleted since it is the latest message\n\n";
    log.generateSomeMessages(10);

    cout << "Output log\n\n";
    log.outputMessageLog();

    cout << "Output last 5 message\n\n";
    log.outputSomeLastElements(5);

}
