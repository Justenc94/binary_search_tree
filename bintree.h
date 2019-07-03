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




    //TODO: Build displayPreOrder Method
    //TODO: Build displayPostOrder Method
    //TODO: Build displayInOrder Method
    //TODO: Build displayTree Method
    //TODO: Build isEmpty Method
    //TODO: Build getCount Method
    //TODO: Build getRootData Method
    //TODO: Build clear Method
    //TODO: Build getNode Method
    //TODO: Build contains Method
    //TODO: Build getHeight Method
    //TODO: Build removeNode Method


private:
    int count;
    DataNode *root;

    //overloaded wrapper functions
    bool addNode(int, string, DataNode);


    //TODO: Build private overload method: clear
    //TODO: Build private overload method: removeNode
    //TODO: Build private overload method: getNode
    //TODO: Build private overload method: contains
    //TODO: Build private overload method: getHeight
    //TODO: Build private overload method: displayPreOrder
    //TODO: Build private overload method: displayPostOrder
    //TODO: Build private overload method: displayTree


};

#endif //BINTREE_H