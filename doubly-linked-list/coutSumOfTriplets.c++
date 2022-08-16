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

int countTriplets(Node *head, int sum){
    Node *tempPtr = head;
    while(tempPtr->next != NULL){
        tempPtr = tempPtr->next;
    }

    Node *startPtr = head;
    Node *endPtr = tempPtr;;


    while(startPtr->data <= endPtr->data){
        
    }
}

int main()
{
    Node *head = new Node(1);
    Node *first = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(4);
    Node *fourth = new Node(5);
    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

}