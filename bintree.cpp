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

//TODO: need to make sure that its accessing a pointer of root because method is never entering recursion

bool BinTree::addNode(int id, string info, DataNode *add_node) {

    if(!add_node->left){
        cout << "\nLeft is null." << endl;
    }else{
        cout << "\nLeft is NOT null." << endl;
    }

    if(!add_node->right){
        cout << "Right is null." << endl;
    }else{
        cout << "Right is NOT null." << endl;
    }

    if(id < add_node->data.id){
        cout << "LEFT" << endl;
        if(!add_node->left){
            auto *temp_node = new DataNode;
            temp_node->data.id = id;
            temp_node->data.information = info;
            add_node->left = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->left);
        }
    }else{
        cout << "RIGHT" << endl;
        if(!add_node->right){
            auto *temp_node = new DataNode;
            temp_node->data.id = id;
            temp_node->data.information = info;
            add_node->right = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->right);
        }
    }
}

