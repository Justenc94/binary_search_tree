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
        root = new DataNode;
        root = tempNode;
        count++;
        return true;
    }else{
        return addNode(id, info, root);
    }

}

bool BinTree::getRootData(Data *temp_data) {
    if(root){
        temp_data->id =  root->data.id;
        temp_data->information =  root->data.information;
        return true;
    }else{
        temp_data->id = -1;
        temp_data->information = "";
        return false;
    }
}

//only used to call overloaded private wrapper method
bool BinTree::getNode(Data *temp_data, int id) {
    return getNode(temp_data, id, root);
}

//only used to call overloaded private wrapper method
bool BinTree::contains(int id) {
    return contains(id, root);
}

void BinTree::displayTree() {
    cout << "DISPLAY TREE" << endl;
    cout << "===============================================" << endl;
    isEmpty() ? cout << "Tree is empty" << endl : cout << "Tree is NOT empty" << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Node Count: " << getCount() << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder();
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder();
    cout << "===============================================" << endl << endl;
}

int BinTree::getCount() {
    return count;
}

//only used to call overloaded private wrapper method
int BinTree::getHeight(){
    return getHeight(root);
}


bool BinTree::isEmpty() {
    if(count == 0){
        return true;
    }else{
        return false;
    }
}

//only used to call overloaded private wrapper method
void BinTree::displayPreOrder() {
    return displayPreOrder(root);
}

//only used to call overloaded private wrapper method
void BinTree::displayPostOrder() {
    return displayPostOrder(root);
}

//only used to call overloaded private wrapper method
void BinTree::displayInOrder() {
    return displayInOrder(root);
}

//only used to call overloaded private wrapper method
void BinTree::clear() {
    clear(root);
}

bool BinTree::removeNode(int id) {
    if(contains(id)){
        root = removeNode(id, root);
        return true;
    }else{
        return false;
    }
}

//**********************************************   PRIVATE METHODS  **********************************************

bool BinTree::addNode(int id, string info, DataNode *add_node) {
    auto *temp_node = new DataNode;
    temp_node->data.id = id;
    temp_node->data.information = info;
    temp_node->left = temp_node->right = nullptr;

    if(id < add_node->data.id){
        if(!add_node->left){
            add_node->left = new DataNode;
            add_node->left = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->left);
        }
    }else{
        if(!add_node->right){
            add_node->right = new DataNode;
            add_node->right = temp_node;
            count++;
        }else{
            addNode(id, info, add_node->right);
        }
    }
}

bool BinTree::getNode(Data *temp_data, int id, DataNode *temp_root) {
    if(!temp_root){
        return false;
    }
    if(temp_root->data.id == id){
        temp_data->id = temp_root->data.id;
        temp_data->information = temp_root->data.information;
        return true;
    }
    bool searchFlagLeft = getNode(temp_data, id, temp_root->left);
    bool searchFlagRight = getNode(temp_data, id, temp_root->right);

    return searchFlagLeft || searchFlagRight;
}

bool BinTree::contains(int id, DataNode *temp_root) {
    if(!temp_root){
        return false;
    }
    if(temp_root->data.id == id){
        return true;
    }
    bool searchFlagLeft = contains(id, temp_root->left);
    bool searchFlagRight = contains(id, temp_root->right);

    return searchFlagLeft || searchFlagRight;
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

DataNode* BinTree::removeNode(int id, DataNode *temp_root) {
    if (temp_root == nullptr) {
        return nullptr;
    }

    //if
    if (id < temp_root->data.id) {
        temp_root->left = removeNode(id, temp_root->left);
    }
    else if (temp_root->data.id < id) {
        temp_root->right = removeNode(id, temp_root->right);
    }

    //case: 1 or less children and left is null
    else if (temp_root->left == nullptr) {
        DataNode* result = temp_root->right;
        delete temp_root;
        count--;
        temp_root = result;
    }

    //case: 1 or less children and right is null
    else if (temp_root->right == nullptr) {
        DataNode* result = temp_root->left;
        delete temp_root;
        count--;
        temp_root = result;
    }

    //case: 2 children
    else {
        int node_pos = minValueNode(temp_root->right);
        temp_root->right = removeNode(node_pos, temp_root->right);
        temp_root->data.id = node_pos;
    }

    //returns a dataNode to update root
    return temp_root;
}

int BinTree::minValueNode(DataNode *temp_node) {
    while(temp_node->left){
        temp_node = temp_node->left;
    }
    return temp_node->data.id;
}

