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

Node *sort2(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *zero = new Node(-1);
    Node *zeroTail = zero;
    Node *first = new Node(-1);
    Node *firstTail = first;
    Node *second = new Node(-1);
    Node *secondTail = second;


    while(head != NULL){
        if(head->data == 0){
            Node *node = new Node(0);
            zeroTail->next = node;
            zeroTail = node;
            head = head->next;
        }
        else if(head->data == 1){
            Node *node = new Node(1);
            firstTail->next = node;
            firstTail = node;
            head = head ->next;
        }
        else if(head->data = 2){
            Node *node = new Node(2);
            secondTail->next = node;
            secondTail = node;
            head = head ->next;
        }
    }

    if(first->next != NULL){
        zeroTail->next = first->next;
        firstTail->next = second->next;
    }
    else{
        zeroTail->next = second->next;
        
    }
    head = zero->next;
    delete (zero);
    delete(first);
    delete(second);
    return head;

}

void sort1(Node *head){
    if(head == NULL){
        return;
    }
    Node *curr = head;
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;
    while(curr != NULL){
        if(curr->data == 0){
            zeroCnt++;
        }
        else if(curr ->data == 1){
            oneCnt++;
        }
        else if(curr ->data == 2){
            twoCnt++;
        }
        curr = curr ->next;
    }
    while(head != NULL){
        if(zeroCnt > 0){
            head->data = 0;
            head = head->next;
            zeroCnt--;
        }
        else if(oneCnt>0){
            head->data = 1;
            head = head->next;
            oneCnt--;
        }
        else if(twoCnt > 0){
            head->data = 2;
            head = head->next;
            twoCnt--;
        }
    }
}

void traverse(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(0);
    Node *second = new Node(1);
    Node *third = new Node(0);
    Node *fourth = new Node(1);
    Node *fifth = new Node(0);
    Node *tail = new Node(2);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail;
    tail->next = NULL;
    traverse(head);
    cout <<"AFTER SORTING ALGORITHM" << endl;
    Node *list = sort2(head);
    traverse(list);


}