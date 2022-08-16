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

Node *meetingPoint(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node *getfirstPos(Node *head){
    if(head == NULL){
        return NULL;
    }
    
    Node *intersection = meetingPoint(head);
    if(intersection == NULL){
        return NULL;
    }
    Node * slow = head;
    Node *fast = intersection;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;

}

void removeLoop(Node * head){
    if(head == NULL){
        return;
    }
    Node *firstPos = getfirstPos(head);
    Node *temp = firstPos;
    while(temp->next != firstPos){
        temp = temp->next;
    }
    temp->next = NULL;
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
    Node *second = new Node(50);
    Node *third = new Node(100);
    Node *tail = new Node(60);
    head->next = second;
    second->next = third;
    third->next = tail;
    tail->next = second;
    cout << meetingPoint(head)->data << endl;
    cout << getfirstPos(head)->data << endl;
    removeLoop(head);
    traverse(head);

}