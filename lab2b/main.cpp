#include <iostream>
#include "source.h"
#include "modes.h"

using namespace std;

int main()
{
    bool isContinued = true;

    while(isContinued){
        cout << "Choose mode\n"
             << "1 - Interactive\n"
             << "2 - Demonstration\n"
             << "3 - exit\n";
        short action;
        cin >> action;
        switch (action){
            case 1:
                interactive();
                break;
            case 2:
                demonstration();
                break;
            case 3: isContinued = false;
                break;
            default: cout << "Choose correct number\n";
        }
    }
    return 0;
}

