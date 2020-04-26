//
// Created by Admin on 06.04.2020.
//

#ifndef LAB4_SOURCE_H
#define LAB4_SOURCE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;



class Tree{
private:
    class Node{
    public:
        int value;
        vector<Node*> leaps;
        Node(int newValue);
    };
    Node* root;
    void outputPath(vector<int> pathToCurrentNode, Node* currentNode);

public:
    Tree(int newValue);
    void output();
    void push_to(int newValue);
};

#endif //LAB4_SOURCE_H
