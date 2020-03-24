#include <iostream>
#include "message.h"
#include "functions.h"
#include "modes.h"
#include <vector>

using namespace std;

int Message::count = 0;

int main()
{
    bool check = true;

    while(check){
        cout << "Choose mode\n"
             << "1 - Interactive\n"
             << "2 - Demonstration\n"
             << "3 - benchmark\n"
             << "4 - exit\n";
        short action;
        cin >> action;
        switch (action){
            case 1: interactive();
                break;
            case 2: demonstration();
                break;
            case 3: benchmark();
                break;
            case 4: check = false;
                break;
            default: cout << "Choose correct number\n";
        }
    }
    return 0;
}
