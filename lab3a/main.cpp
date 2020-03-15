#include "modes.h"

int main() {
    bool check = true;

    while(check){
        cout << "Choose mode\n"
             << "1 - Demonstration\n"
             << "2 - Benchmark\n"
             << "3 - exit\n";

        short action;
        cin >> action;

        switch (action){
            case 1:
                demonstration();
                break;
            case 2:
                benchmark();
                break;
            case 3:
                check = false;
                break;
            default: cout << "Choose correct number\n";
        }
    }

    return 0;
}
