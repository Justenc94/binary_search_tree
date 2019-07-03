/***********************************************************
Name: Justen Crockett
Assignment: 05
Purpose:
***********************************************************/

#include "bintree.h"

BinTree::BinTree() {
    count = 0;
    root = nullptr;
}

//**********************************************   PUBLIC METHODS  **********************************************

bool BinTree::addNode(int id, string info){
    if(root == nullptr){
        root = new DataNode;
        root->data.id = id;
        root->data.information = info;
        root->left = root->right = nullptr;
        cout << "ADDED ROOT: " << info << endl;         //DEBUG ONLY ************* NEED TO REMOVE
        return true;
    }else{
        return addNode(id, info, *root);
    }
}


//**********************************************   PRIVATE METHODS  **********************************************


bool BinTree::addNode(int id, string info, DataNode tempNode) {
    if(tempNode.data.id > id){
        if(tempNode.left == nullptr){
            tempNode.left = new DataNode;
            tempNode.left->data.id = id;
            tempNode.left->data.information = info;
            tempNode.left = tempNode.right = nullptr;
            cout << "ADDED LEFT" << info << endl;           //DEBUG ONLY ************* NEED TO REMOVE
            return true;
        }else{
            addNode(id, info, *tempNode.left);
        }
    }else if(tempNode.data.id < id){
        if(tempNode.right == nullptr){
            tempNode.right = new DataNode;
            tempNode.right->data.id = id;
            tempNode.right->data.information = info;
            tempNode.right = tempNode.right = nullptr;
            cout << "ADDED RIGHT" << info << endl;          //DEBUG ONLY ************* NEED TO REMOVE
            return true;
        }else{
            addNode(id, info, *tempNode.right);
        }
    }else{
        return false;
    }
}

