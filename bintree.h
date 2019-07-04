/***********************************************************
Name: Justen Crockett
Assignment: 05
Purpose:
***********************************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include "main.h"
#include "data.h"

class BinTree {

public:
    //constructor
    BinTree();

    //destructor
    //~BinTree();

    bool addNode(int, string);
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    void displayTree();
    int getCount();

    //TODO: Build isEmpty Method
    //TODO: Build getRootData Method
    //TODO: Build clear Method
    //TODO: Build getNode Method
    //TODO: Build contains Method
    //TODO: Build getHeight Method
    //TODO: Build removeNode Method


private:
    int count;
    struct DataNode *root;

    //overloaded private wrapper functions
    bool addNode(int, string, DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);


    //TODO: Build private overload method: clear
    //TODO: Build private overload method: removeNode
    //TODO: Build private overload method: getNode
    //TODO: Build private overload method: contains
    //TODO: Build private overload method: getHeight



};

#endif //BINTREE_H