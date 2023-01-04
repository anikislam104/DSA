//
// Created by aniki on 1/4/2023.
//

#include "iostream"
#include "stack"
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* create_list(){
    //create a linked list with elements 4,1,2,7,3
    Node* start = new Node();
    start->data = 4;
    Node* node2 = new Node();
    node2->data = 1;
    start->next = node2;
    Node* node3 = new Node();
    node3->data = 2;
    node2->next = node3;
    Node* node4 = new Node();
    node4->data = 7;
    node3->next = node4;
    Node* node5 = new Node();
    node5->data = 3;
    node4->next = node5;
    node5->next = nullptr;
    return start;
}

void print_list(Node* start){
    Node* temp = start;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse_the_list(Node* start){
    stack<Node*> s;
    Node* curr=start;
    while (curr->next!= nullptr){
        s.push(curr);
        curr=curr->next;
    }
    Node* new_start=curr;
    while (!s.empty()){
        Node* parent=s.top();
        curr->next=parent;
        curr=parent;
        s.pop();
    }
    return new_start;
}

int main(){
    Node* start = create_list();
    print_list(start);
    Node* reversed_list_start= reverse_the_list(start);
    print_list(reversed_list_start);
}
