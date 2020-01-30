#include <iostream>
#include <message.h>
#include <fstream>
#include <vector>

using namespace std;

void interactive(){
    bool check = 1;
    while (check){
        int action;
        cout << "Select next action: \n"
             << "1 - Add new obj \n"
             << "2 - Saving data to txt\n"
             << "3 - Saving data to bin\n"
             << "4 - Reading from txt \n"
             << "5 - Reading from bin \n"
             << "6 - Updating \n"
             << "7 - Deleting \n"
             << "8 - Exit \n";
        cin >> action;
        switch(action){
            case 8: break;
            case 1: cout << "Interactive dialog window \n"
                    << "Choose next action \n";
                    break;
            case 2: cout << "Demonstration \n"
                    << "Choose next action \n";
                    break;
            case 3: cout << "benchmark \n";
                    break;
        }
        cout << "Do you want to continue with Interactive dialog window? 0/1, 0 - No, 1 - Yes \n";
        cin >> check;
    }
}

int main()
{
    vector<MessageLog> messageLog;

    MessageLog message;
    message.id = 2;
    message.text = "hello guys, go";
    message.timeInSec = time(NULL);
    message.typeOfError = "error";
    message.priority = 140;
    message.loading = 0;
    bool check = 1;
    while(check){
        int action;
        cout << "Select next action: \n"
             << "1 - Interactive dialog window \n"
             << "2 - Demonstration \n"
             << "3 - benchmark \n";
        cin >> action;
        switch(action){
            case 1: cout << "You have chosen Interactive dialog window \n";
                    interactive();
                    break;
            case 2: cout << "You have chosen Demonstration \n";
                    break;
            case 3: cout << "You have chosen benchmark \n";
                    break;
        }
        cout << "Do you want to continue work? 0/1, 0 - No, 1 - Yes \n";
        cin >> check;
    }
    return 0;
}
