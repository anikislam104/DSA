//
// Created by aniki on 12/29/2022.
//
#include "iostream"
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    Node* start;
    LinkedList() {
        start = NULL;
    }
};

Node* create_node(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

LinkedList* create_list(Node** nodes,int* data, int n){
    for(int i=0;i<n;i++){
        nodes[i] = create_node(data[i]);
    }
    for(int i=0;i<n-1;i++){
        nodes[i]->next = nodes[i+1];
    }
    LinkedList* list = new LinkedList();
    list->start = nodes[0];
    return list;
}

void insert_node_at_the_beginning(Node* newNode, LinkedList* list){
    newNode->next = list->start;
    list->start = newNode;
}

void insert_node_at_the_end(Node* newNode, LinkedList* list){
    Node* temp = list->start;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_node_at_the_middle(Node* newNode, LinkedList* list, int position){
    Node* temp = list->start;
    for(int i=0;i<position-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_node_at_the_beginning(LinkedList* list){
    Node* temp = list->start;
    list->start = list->start->next;
    delete temp;
}

void delete_node_at_the_end(LinkedList* list){
    Node* temp = list->start;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void delete_node_at_the_middle(LinkedList* list, int position){
    Node* temp = list->start;
    for(int i=0;i<position-1;i++){
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

void print_list(LinkedList* list){
    Node* temp = list->start;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int count_the_number_of_nodes(Node* start){
    if(start==nullptr){
        return 0;
    }
    else{
        return 1+count_the_number_of_nodes(start->next);
    }
}

int main(){
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(data)/sizeof(data[0]);
    Node* nodes[n];
    //create a linked list
    LinkedList* list = create_list(nodes, data, n);
    //insert a node
    Node* newNode = create_node(0);
    insert_node_at_the_beginning(newNode, list);
    Node* newNode2 = create_node(11);
    insert_node_at_the_end(newNode2, list);
    Node* newNode3 = create_node(100);
    insert_node_at_the_middle(newNode3, list, 5);
    //print the list
    cout<<"The list after inserting is: ";
    print_list(list);
    //delete a node
    delete_node_at_the_beginning(list);
    delete_node_at_the_end(list);
    delete_node_at_the_middle(list, 4);
    //print the list
    cout<<endl<<"The list after deleting is: ";
    print_list(list);
    //count the number of nodes
    cout<<endl<<"The number of nodes in the list is: "<<count_the_number_of_nodes(list->start);
    return 0;
}