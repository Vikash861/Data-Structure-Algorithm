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

Node *breakIntoHalves(Node *last,Node* head, Node *&secondList, int total){

    int mid = total/2;
    int cnt= 1;
    Node *curr = head;
    while(cnt < mid){
        curr = curr->next;
        cnt++;
    }
    secondList = curr->next;
    curr->next = NULL;
    cout << curr->next << endl;
    return head;

}

Node *getCountAndLastPos(Node *head, Node *&secondList){
    Node *curr = head->next;
    int cnt = 2;
    while(curr->next != head){
        curr = curr->next;
        cnt++;
    }
    curr->next = NULL;
    return breakIntoHalves(curr,head,secondList,cnt);
}


void traverse(Node *head)
{
    if (head == NULL)
    {
        cout << "there is nothing to print in linked list" << endl;
        return;
    }
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

void traverse2(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(30);
    Node *tail = new Node(60);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;
    tail->next = head;
    traverse(head);
    cout << endl;
    Node *secondList =  NULL;
    Node *firstList = getCountAndLastPos(head,secondList);
    cout << "Two Lists are" << endl;
    traverse2(firstList);
    cout << endl;
    traverse2(secondList);



}