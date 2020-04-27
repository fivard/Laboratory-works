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
Tree::~Tree(){
    cout << "Destructor: \n";
    destroyNode(root);
}

Tree::Node* Tree::getRoot() {
    return root;
}


void Tree::outputWithPath(vector<int> pathToCurrentNode, Node* currentNode) {
    cout << "path = ";
    for (int i : pathToCurrentNode)
        cout << i << '\t';
    cout << ": value = " << currentNode->value << '\n';

    for (int i = 0; i < currentNode->leaps.size(); i++) {
        pathToCurrentNode.push_back(i);
        outputWithPath(pathToCurrentNode, currentNode->leaps[i]);
        pathToCurrentNode.pop_back();
    }
}

void Tree::outputWithIndent(Node* currentNode, int countOfIndents) {

    cout << currentNode << " : val = " << currentNode->value << '\n';
    countOfIndents++;

    for (int i = 0; i < currentNode->leaps.size(); i++) {
        for (int j = 0; j < countOfIndents; j++)
            cout << '\t';
        cout << i << ". ";
        outputWithIndent(currentNode->leaps[i], countOfIndents);
    }
}

void Tree::push_to(int newValue) {
    Node* currentNode = root;
    int indexOfNode;

    if (root->leaps.empty()){
        Node* newNode = new Node(newValue);
        root->leaps.push_back(newNode);
        cout << "Tree is empty. Node is added to root\n";
        return;
    }

    while (true){
        outputWithIndent(currentNode);

        if (currentNode->leaps.empty()){
            Node* newNode = new Node(newValue);
            currentNode->leaps.push_back(newNode);
            return;
        }

        cout << "Available leaps: ";
        for (int i = 0; i < currentNode->leaps.size(); i++)
            cout << i << ' ';
        cout << "\nChoose the leap or enter \"-1\" and new node will be added here\n";

        cin >> indexOfNode;

        if (indexOfNode >= int(currentNode->leaps.size()) || indexOfNode < -1)
            cout << "Wrong case\n";
        else if (indexOfNode == -1) {
            Node* newNode = new Node(newValue);
            currentNode->leaps.push_back(newNode);
            return;
        } else
            currentNode = currentNode->leaps[indexOfNode];

    }
}

void Tree::deleteSubTree() {
    Node* currentNode = root;
    Node* previousNode = root;
    int indexOfNode = -1, action;

    if (root->leaps.empty()) {
        cout << "Root hasn't got leaps.\n";
        return;
    }

    while(true){
        outputWithIndent(currentNode);

        if (currentNode->leaps.empty()){
            cout << "This node hasn't got a leap\n";
            previousNode->leaps.erase(previousNode->leaps.begin()+indexOfNode);
            destroyNode(currentNode);
            return;
        }

        cout << "Available leaps: ";
        for (int i = 0; i < currentNode->leaps.size(); i++)
            cout << i << ' ';
        cout << "\nChoose the leap or press \"-1\" and current node will be deleted\n";

        cin >> action;

        if (action < -1 || action >= int(currentNode->leaps.size()))
            cout << "Wrong case\n";
        else if (action == -1){
            if (indexOfNode == -1) {
                cout << "You cant delete root\n";
                continue;
            }
            previousNode->leaps.erase(previousNode->leaps.begin()+indexOfNode);
            destroyNode(currentNode);
            return;
        } else {
            indexOfNode = action;
            previousNode = currentNode;
            currentNode = currentNode->leaps[indexOfNode];
        }
    }
}

void Tree::destroyNode(Tree::Node* currentNode) {
    for (auto & leap : currentNode->leaps)
        destroyNode(leap);
    cout << "Delete node " << currentNode << "\n" ;
    delete currentNode;
}