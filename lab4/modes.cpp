//
// Created by Admin on 26.04.2020.
//

#include "modes.h"

void interactive(){
    int root;
    cout << "Enter root value = ";
    cin >> root;
    Tree tree(root);
    vector<int> pathForPushing;
    bool continued = true;

    while (continued) {
        cout << "\nChoose your action\n"
             << "1 - push new element\n"
             << "2 - output tree with path\n"
             << "3 - output tree with indents\n"
             << "4 - delete some subtree\n"
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
                Tree::outputWithPath(pathForPushing, tree.getRoot());
                break;
            case 3:
                Tree::outputWithIndent(tree.getRoot());
                break;
            case 4:
                tree.deleteSubTree();
                break;
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