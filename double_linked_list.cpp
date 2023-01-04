//
// Created by aniki on 12/29/2022.
//
#include "iostream"
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

class LinkedList {
public:
    Node* start;
    LinkedList() {
        start = NULL;
    }
};

Node* create_node(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
    //time complexity: O(1)
    //space complexity: O(1)
}

void insert_node_at_the_beginning(Node* newNode, LinkedList* list){
    newNode->right = list->start;
    list->start->left = newNode;
    list->start = newNode;
    //time complexity: O(1)
    //space complexity: O(1)
}

void print_list(LinkedList* list){
    Node* temp = list->start;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
    //time complexity: O(n)
    //space complexity: O(1)
}

int main(){
    Node* start= create_node(1);
    LinkedList* list = new LinkedList();
    list->start = start;
    insert_node_at_the_beginning(create_node(0), list);
    print_list(list);
}