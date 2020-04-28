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
        explicit Node(int newValue);
    };
    Node* root;

public:
    explicit Tree(int newValue);
    ~Tree();
    Node* getRoot();
    static void outputWithPath(vector<int> pathToCurrentNode, Node* currentNode);
    static void outputWithIndent(Node* currentNode, int countOfIndents = 0);
    void push(int newValue);
    Node* deleteSubTree();
    static void destroyNode(Node* currentNode);
};

class BinaryTree{
private:
    class Node{
    public:
        int value;
        Node* left;
        Node* right;
        explicit Node(int newValue);
    };
    Node* root;

public:
    Node* getRoot();
    ~BinaryTree();
    explicit BinaryTree(int newValue);
    static void outputBinaryTree(Node* currentNode, int countOfIndents = 0);
    void push(int newValue);
    void destroyNode(Node* currentNode);
};

#endif //LAB4_SOURCE_H
