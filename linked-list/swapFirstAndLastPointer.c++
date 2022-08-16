#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
    }
};

Node *swapNode(Node *head){

    if(head->next->next == NULL){
        Node *prev = head;
        Node *next = head->next;
        prev->next = next->next;
        next->next = prev;
        return next;
    }

    Node *prev = head;
    Node *next = head->next;
    while(next->next != NULL){
        prev = prev->next;
        next = next->next;
    }

    prev->next = next->next;
    next->next = head;

    return next;
}

void traverse(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(5);
    Node *fifth = new Node(11);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next =  NULL;
    Node *ansList = swapNode(head);
    traverse(ansList);

}