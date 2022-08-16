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
        cout << head->data << " ";
        head = head->next;
    }
}


Node* reverseDLL(Node * head)
{
    if(head == NULL || (head->prev == NULL && head->next==NULL)){
        return head;
    }
    
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr = NULL;
    
    // loop will be happen here
    while(currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        currPtr->prev = nextPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    
    return prevPtr;
    
}



Node *reverseInGroup(Node *head, int k){


    Node *currPtr = head;

    while(currPtr != NULL){
        if(currPtr->prev == NULL){
            Node *nextPtr = currPtr;
            int cnt = 0;
            while(cnt  <  k){
                nextPtr = nextPtr->next;
                cnt++;
            }

            Node *prevPtr = nextPtr->prev;
            prevPtr->next = NULL;
            nextPtr->prev = NULL;

            Node *revList = reverseDLL(currPtr);
            while(revList->next != NULL){
                revList = revList->next;
            }
            revList->next = nextPtr;
            nextPtr->prev = revList;

            currPtr = revList;
        }
        currPtr = currPtr->next;
    }
    return head;
}

int main()
{


    Node *head = new Node(1);
    Node *second = insertAtTail(head,2);
    Node *fourth = insertAtTail(second,4);
    Node *fifth = insertAtTail(fourth,5);
    Node *sixth = insertAtTail(fifth,6);
    Node *eight = insertAtTail(sixth,8);
    Node *nine = insertAtTail(eight,9);
    traverse(reverseInGroup(head,2));


}