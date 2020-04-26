//
// Created by Admin on 26.04.2020.
//

#include "modes.h"

void interactive(){
    int root;
    cout << "Enter root value ";
    cin >> root;
    Tree tree(root);
    bool continued = true;

    while (continued) {
        cout << "\nChoose your action\n"
             << "1 - push new element\n"
             << "2 - output tree with path\n"
             << "3 - output tree with indents\n"
             << "100 - exit\n";

        int action;
        cin >> action;

        switch(action) {
            case 1:
                int newValue;
                cout << "Enter new value\n";
                cin >> newValue;
                tree.push_to(newValue);
                break;
            case 2:
                tree.outputWithPath();
                break;
            case 3:
                tree.outputWithIndent(tree.getRoot());
            case 100:
                continued = false;
                break;
            default:
                cout << "Wrong case\n";
        }
    }
}

void demonstration(){
    return;
}