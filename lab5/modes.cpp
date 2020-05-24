//
// Created by Admin on 24.05.2020.
//

#include "modes.h"

void interactive(){
    cout << "Choose\n"
    << "1. Approximate\n"
    << "0. Not approximate\n";
    bool approximation;
    cin >> approximation;

    cout << "Choose started count of nodes\n";
    int countOfNodes;
    cin >> countOfNodes;
    AdjacencyMatrix graph(countOfNodes, approximation);

    while (true) {
        cout << "\nChoose tree\n"
             << "1 - output graph\n"
             << "2 - add new edge\n"
             << "3 - add new node\n"
             << "4 - exit\n";

        int action;
        cin >> action;

        switch(action) {
            case 1:
                graph.output();
                break;
            case 2:
                graph.addNewEdge();
                break;
            case 3:
                graph.addNewNode();
                break;
            case 4:
                return;
            default:
                cout << "Wrong case\n";
        }
    }
}

void demonstration(){

}
void benchmark(){

}