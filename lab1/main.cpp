#include <iostream>
#include "message.h"
#include "functions.h"
#include "modes.h"
#include <vector>

using namespace std;

int MessageLog::count = 0;

int main()
{
    Functions function;
    MessageLog message;

    function.log.clear();

    Functions::defineId();

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
            case 1: check = interactive(function);
                    break;
            case 2: check = demonstration();
                    break;
            case 3: check = benchmark();
                    break;
            case 4: check = false;
                    break;
            default: cout << "Choose correct number\n";
        }
    }
    return 0;
}
