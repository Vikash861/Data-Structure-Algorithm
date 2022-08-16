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

int giveCount(Node *firstPtr, Node *lastPtr, int value){
    int cnt = 0;

    while(firstPtr != NULL && lastPtr != NULL && 
           firstPtr != lastPtr && lastPtr->next != firstPtr){
        if( firstPtr->data + lastPtr->data == value ){
            cnt++;
            firstPtr = firstPtr->next;
            lastPtr = lastPtr->prev;
        }
        else if( firstPtr->data + lastPtr->data < value ){
            firstPtr = firstPtr->next;
        }
        else{
            lastPtr = lastPtr->prev;
        }
    }

    return cnt;
}

int countTriplets(Node *head, int x){
    if(head == NULL){
        return -1;
    }
    Node *lastPtr = head;
    while(lastPtr->next != NULL){lastPtr = lastPtr->next;}
    int count = 0;
    for(Node *currPtr = head; currPtr != NULL; currPtr = currPtr->next){
        Node *firstPtr = currPtr->next;
        count = count + giveCount(firstPtr,lastPtr,x-currPtr->data);
    }
    return count;
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
    cout << countTriplets(head,17) << endl;
    traverse(head);


}