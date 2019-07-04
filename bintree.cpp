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

void BinTree::displayTree() {
    cout << "DISPLAY TREE" << endl;
    cout << "===============================================" << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << "===============================================" << endl;
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void BinTree::displayInOrder() {
    displayInOrder(root);
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

void BinTree::displayPreOrder(DataNode *print_node) {
    if(!print_node){
        return;
    }
    cout << "ID: " << print_node->data.id << "\tInformation: " << print_node->data.information << endl;
    displayPreOrder(print_node->left);
    displayPreOrder(print_node->right);
}

void BinTree::displayPostOrder(DataNode *print_node) {
    if(!print_node){
        return;
    }
    displayPostOrder(print_node->left);
    displayPostOrder(print_node->right);
    cout << "ID: " << print_node->data.id << "\tInformation: " << print_node->data.information << endl;
}

void BinTree::displayInOrder(DataNode *print_node) {
    if(!print_node){
        return;
    }
    displayInOrder(print_node->left);
    cout << "ID: " << print_node->data.id << "\tInformation: " << print_node->data.information << endl;
    displayInOrder(print_node->right);
}

