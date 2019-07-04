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
    auto *tempNode = new DataNode;

    if(root == nullptr){
        tempNode->data.id = id;
        tempNode->data.information = info;
        tempNode->left = tempNode->right = nullptr;
        root = tempNode;
        count++;
        return true;
    }else{
        return addNode(id, info, root);
    }

}


//**********************************************   PRIVATE METHODS  **********************************************

bool BinTree::addNode(int id, string info, DataNode *add_node) {

    if(id < add_node->data.id){
        if(!add_node->left){
            auto *temp_node = new DataNode;
            temp_node->data.id = id;
            temp_node->data.information = info;
            temp_node->left = temp_node->right = nullptr;
            add_node->left = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->left);
        }
    }else{
        if(!add_node->right){
            auto *temp_node = new DataNode;
            temp_node->data.id = id;
            temp_node->data.information = info;
            temp_node->left = temp_node->right = nullptr;
            add_node->right = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->right);
        }
    }
}

