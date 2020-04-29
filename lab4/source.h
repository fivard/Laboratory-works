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

///----------------------------Tree-------------------------///

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

///----------------------------BinaryTree-------------------------///

class BinaryTree{
private:
    class Node{
    public:
        int value;
        Node* left;
        Node* right;
        explicit Node(int newValue);
    };

    struct NodeOfConsistentStorage{
        int value;
        size_t right;
        bool isLeft;
    } ;

    size_t DFSBuildConsistentStorage(Node* currentNode, size_t currentNumber);

    size_t countOfNods;
    Node* root;
    NodeOfConsistentStorage* storage;

public:
    Node* getRoot();
    ~BinaryTree();
    explicit BinaryTree(int newValue);
    static void outputBinaryTree(Node* currentNode, int countOfIndents = 0);
    void push(int newValue);
    static void destroyNode(Node* currentNode);
    void buildConsistentStorage();
    void outputConsistentStorage();
};

#endif //LAB4_SOURCE_H
