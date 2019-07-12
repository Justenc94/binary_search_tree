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

    //destructor that calls clear method
    ~BinTree();

    //public methods - with no private wrapper
    void displayTree();
    int getCount();
    bool isEmpty();
    bool getRootData(Data*);

    //public methods - with overloaded private wrapper method
    bool addNode(int, string);
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    void clear();
    int getHeight();
    bool getNode(Data*, int);
    bool contains(int);
    bool removeNode(int);

    //TODO: Build removeNode Method


private:
    //keeps the node count
    int count;
    //creates the root (initialized as nullptr)
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
    int minValueNode(DataNode*);
    DataNode *removeNode(int, DataNode*);

    //TODO: Build private overload method: removeNode

};

#endif //BINTREE_H