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



void traverse(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}


Node *reverse(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


Node *add1ToTheList(Node *start,Node *head,int carry = 0,int sum = 1){
    if(head->next == NULL){
        head->data = head->data+carry;
        return start;
    }
    sum = sum+head->data+carry;
    int rem = sum%10;
    head->data = rem;
    carry = sum/10;
    return add1ToTheList(start,head->next,carry,sum=0);
}


Node *call(Node *head){

    if(head->next == NULL){
        int val = head->data;
        val = val+1;
        head->data = val;
        return head;
    }

    Node *revList = reverse(head);
    Node *ansList = add1ToTheList(revList,revList);
    ansList = reverse(ansList);
    return ansList;
}


int main()
{
    Node *head = new Node(9);
    Node *second = new Node(9);
    head->next = second;
    second->next = NULL;
    // third->next = NULL;



    Node *ansList = call(head);

    traverse(ansList);




}  