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

void Tree::outputPath(vector<int> pathToCurrentNode, Node* currentNode) {
    for (int i = 0; i < pathToCurrentNode.size(); i++)
        cout << pathToCurrentNode[i] << '\t';
    cout << ": " << currentNode->value << '\n';

    for (int i = 0; i < currentNode->leaps.size(); i++){
        pathToCurrentNode.push_back(i+1);
        outputPath(pathToCurrentNode, currentNode->leaps[i]);
        pathToCurrentNode.pop_back();
    }
}

void Tree::output() {
    string currentPath;
    cout << "root: " << root->value << '\n';
    vector<int> path;
    for (int i = 0; i < root->leaps.size(); i++) {
        path.push_back(i+1);
        outputPath(path, root->leaps[i]);
        path.pop_back();
    }
}

void Tree::push_to(int newValue) {
    Node* currentNode = root;
    bool inputEnd = true;
    int nodeInPath;

    if (root->leaps.size() == 0){
        Node* newNode = new Node(newValue);
        root->leaps.push_back(newNode);
        cout << "Tree is empty. Added to root\n";
        return;
    }

    while (inputEnd){
        if (currentNode->leaps.size() == 0){
            Node* newNode = new Node(newValue);
            currentNode->leaps.push_back(newNode);
            cout << "Node is empty. Added here\n";
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