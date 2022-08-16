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


void removeDuplicates(Node * curr){

    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else{
            curr = curr->next;
        }
    }
}

void traverse(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(10);
    Node *third = new Node(20);
    Node *tail = new Node(20);
    head->next = second;
    second->next = third;
    third->next = tail;
    traverse(head);
    cout << endl;
    cout << "LIST AFTER DELETION " << endl;
    removeDuplicates(head);
    traverse(head);

}