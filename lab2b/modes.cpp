//
// Created by Admin on 05.03.2020.
//

#include "modes.h"
#include "source.h"

void interactive(){
    HashedArrayTree tree;
    bool continued = true;

    while (continued) {
        cout << "Choose your action\n"
             << "1 - push_back new element\n"
             << "2 - pop_back\n"
             << "3 - clear\n"
             << "4 - output tree\n"
             << "5 - is empty\n"
             << "6 - generate some elements to the end\n"
             << "7 - search element by index\n"
             << "8 - search first index by value\n"
             << "9 - delete by index\n"
             << "10 - insert by index\n"
             << "100 - exit\n";

        int action;
        cin >> action;

        switch(action){
            case 1:
                int newElement;
                cout << "Enter new element \n";
                cin >> newElement;
                tree.push_back(newElement);
                break;
            case 2:
                tree.pop_back();
                break;
            case 3:
                tree.clear();
                break;
            case 4:
                tree.outputTree();
                break;
            case 5:
                if (tree.empty())
                    std::cout << "True\n";
                else
                    std::cout << "False\n";
                break;
            case 6:
                int countOfElements;
                cout << "Enter count of elements \n";
                cin >> countOfElements;
                tree.generateSomeElementsToTheEnd(countOfElements);
                break;
            case 7:
                int index;
                cout << "Enter an index of searched element\n";
                cin >> index;
                cout << "The element which has index " << index << " is: " << tree.searchByIndex(index) << endl;
                break;
            case 8:
                int value;
                cout << "Enter an value of searched element\n";
                cin >> value;
                cout << "The element which value is " << value << " has index: "
                << tree.searchByValue(value) << endl;
                break;
            case 9:
                int indexDeleting;
                cout << "Enter an index of deleting element\n";
                cin >> indexDeleting;
                tree.deleteByIndex(indexDeleting);
                break;
            case 10:
                int valueInserting, indexInserting;
                cout << "Enter a value of inserting element\n";
                cin >> valueInserting;
                cout << "Enter an index of inserting element\n";
                cin >> indexInserting;
                tree.insertByIndex(valueInserting, indexInserting);
                break;
            case 100:
                continued = false;
                break;
            default:
                std::cout << "Wrong number\n";
                break;
        }
    }
}
