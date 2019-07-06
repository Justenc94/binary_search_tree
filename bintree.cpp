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

BinTree::~BinTree() {
    clear();
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
    isEmpty() ? cout << "Tree is NOT empty" << endl : cout << "Tree is empty" << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Node Count: " << getCount() << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder();
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder();
    cout << "===============================================" << endl;
}

int BinTree::getCount() {
    return count;
}

int BinTree::getHeight(){
    getHeight(root);
}


bool BinTree::isEmpty() {
    if(count != 0){
        return true;
    }else{
        return false;
    }
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

void BinTree::clear() {
    clear(root);
}


//**********************************************   PRIVATE METHODS  **********************************************

bool BinTree::addNode(int id, string info, DataNode *add_node) {
    auto *temp_node = new DataNode;
    temp_node->data.id = id;
    temp_node->data.information = info;
    temp_node->left = temp_node->right = nullptr;

    if(id < add_node->data.id){
        if(!add_node->left){
            add_node->left = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->left);
        }
    }else{
        if(!add_node->right){
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
    cout << print_node->data.id << " " << print_node->data.information << endl;
    displayPreOrder(print_node->left);
    displayPreOrder(print_node->right);
}

void BinTree::displayPostOrder(DataNode *print_node) {
    if(!print_node){
        return;
    }
    displayPostOrder(print_node->left);
    displayPostOrder(print_node->right);
    cout << print_node->data.id << " " << print_node->data.information << endl;
}

void BinTree::displayInOrder(DataNode *print_node) {
    if(!print_node){
        return;
    }
    displayInOrder(print_node->left);
    cout << print_node->data.id << " " << print_node->data.information << endl;
    displayInOrder(print_node->right);
}

int BinTree::getHeight(DataNode *temp_node){
    if(!temp_node){
        return 0;
    }
    return 1 + std::max(getHeight(temp_node->left), getHeight(temp_node->right));
}

void BinTree::clear(DataNode *temp_node) {
    if(temp_node != nullptr){
        clear(temp_node->left);
        clear(temp_node->right);
        delete temp_node;
        if(temp_node->left != nullptr){
            temp_node->left = nullptr;
        }
        if(temp_node->right != nullptr){
            temp_node->right = nullptr;
        }
        root = nullptr;
        count = 0;
    }
}
