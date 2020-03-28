#include "source.h"

int main() {
    bool isContinued = true;
    while(isContinued){
        cout << "Choose mode\n"
             << "1 - Demonstration\n"
             << "2 - benchmark\n"
             << "3 - exit\n";
        short action;
        cin >> action;
        switch (action){
            break;
            case 1: demonstration();
                break;
            case 2: benchmark();
                break;
            case 3: isContinued = false;
                break;
            default: cout << "Choose correct number\n";
        }
    }
    return 0;
}
