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
    ~BinTree();

    bool addNode(int, string);
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    void displayTree();
    int getCount();
    bool isEmpty();
    void clear();
    int getHeight();
    bool getRootData(Data*);
    bool getNode(Data*, int);
    bool contains(int);

    //TODO: Build removeNode Method


private:
    int count;
    struct DataNode *root;

    //overloaded private wrapper functions
    bool addNode(int, string, DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    void clear(DataNode*);
    int getHeight(DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);

    //TODO: Build private overload method: contains



};

#endif //BINTREE_H