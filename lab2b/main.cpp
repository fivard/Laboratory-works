#include <iostream>
#include "source.h"

using namespace std;

int main()
{
    bool isContinued = true;
    HashedArrayTree tree;
    for (int i = 0; i < 16; i++)
        tree.push_back(i);

    tree.coutTree();

    tree.push_back(16);

    tree.coutTree();

    for (int i = 0; i < 9; i++)
        tree.pop_back();

    tree.coutTree();

    tree.push_back(8);

    tree.coutTree();

    /*while(isContinued){
        cout << "Choose mode\n"
             << "1 - Interactive\n"
             << "2 - Demonstration\n"
             << "3 - exit\n";
        short action;
        cin >> action;
        switch (action){
            case 1:
                break;
            case 2:
                break;
            case 3: isContinued = false;
                break;
            default: cout << "Choose correct number\n";
        }
    }*/
    return 0;
}

