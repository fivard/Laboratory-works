//
// Created by Admin on 06.04.2020.
//

#include "source.h"

Tree::Node::Node(int newValue) {
    value = newValue;
}

Tree::Tree(int newValue){
    root = new Node(newValue);
}

Tree::Node* Tree::getRoot() {
    return root;
}

void Tree::outputPath(vector<int> pathToCurrentNode, Node* currentNode) {
    cout << "path = ";
    for (int i = 0; i < pathToCurrentNode.size(); i++)
        cout << pathToCurrentNode[i] << '\t';
    cout << ": value = " << currentNode->value << '\n';

    for (int i = 0; i < currentNode->leaps.size(); i++){
        pathToCurrentNode.push_back(i+1);
        outputPath(pathToCurrentNode, currentNode->leaps[i]);
        pathToCurrentNode.pop_back();
    }
}
void Tree::outputWithPath() {
    cout << "TREE OUTPUT\n"
         << "root: " << root->value << '\n';
    vector<int> path;
    for (int i = 0; i < root->leaps.size(); i++) {
        path.push_back(i+1);
        outputPath(path, root->leaps[i]);
        path.pop_back();
    }
}
void Tree::outputWithIndent(Node* currentNode, int countOfIndents) {
    for (int i = 0; i < countOfIndents; i++)
        cout << "\t";
    cout << ": " << currentNode->value << '\n';
    countOfIndents++;
    for (int i = 0; i < currentNode->leaps.size(); i++)
        outputWithIndent(currentNode->leaps[i], countOfIndents);
}

void Tree::push_to(int newValue) {
    Node* currentNode = root;
    bool inputEnd = true;
    int nodeInPath;

    if (root->leaps.empty()){
        Node* newNode = new Node(newValue);
        root->leaps.push_back(newNode);
        cout << "Tree is empty. Node is added to root\n";
        return;
    }

    while (inputEnd){
        if (currentNode->leaps.empty()){
            Node* newNode = new Node(newValue);
            currentNode->leaps.push_back(newNode);
            cout << "Current node hasn't leaps. Added here\n";
            return;
        }
        cout << "Available leaps: ";
        for (int i = 0; i < currentNode->leaps.size(); i++)
            cout << i+1 << ' ';
        cout << "\nChoose the leap\n"
            << "0 - exit and add to the end of the current node\n";

        cin >> nodeInPath;
        if (nodeInPath > currentNode->leaps.size() || nodeInPath < 0)
            cout << "Wrong node\n";
        else if (nodeInPath == 0) {
            inputEnd = false;
            Node* newNode = new Node(newValue);
            currentNode->leaps.push_back(newNode);
        }
        else
            currentNode = currentNode->leaps[nodeInPath-1];

    }
}