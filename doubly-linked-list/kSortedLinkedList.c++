#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next =  NULL;
    }
};

Node* insertAtTail(Node *head, int value){
    Node *newNode = new Node(value);
    head->next = newNode;
    newNode->prev = head;
    return newNode;
}

void traverse(Node *head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }
}


Node *sortedDll(Node *head, int k)
{
    Node *headPtr = head;
    while(headPtr->next != NULL){
        Node *currPtr = headPtr->next;
        Node *cmp = headPtr;
        int cnt = 0;
        while(cmp != NULL && cnt < k){
            
            if(currPtr->data < cmp->data){
                swap(currPtr->data, cmp->data);
                cnt++;
                cmp = cmp->prev;
            }
            else{
                cmp = cmp->prev;
                cnt++;
            }
            
        }
        headPtr = headPtr->next;

    }
    return head;
}

int main()
{


    Node *head = new Node(6);
    Node *second = insertAtTail(head,5);
    Node *fourth = insertAtTail(second,3);
    Node *fifth = insertAtTail(fourth,2);
    Node *sixth = insertAtTail(fifth,8);
    Node *eight = insertAtTail(sixth,10);
    Node *nine = insertAtTail(eight,9);
    traverse(head);
    cout << "After sorting" << endl;
    Node *newList= sortedDll(head,4);
    traverse(newList);


}

// 6 5 3 2 8 10 9 -1/