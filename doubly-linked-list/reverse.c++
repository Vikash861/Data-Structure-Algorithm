#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};


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
