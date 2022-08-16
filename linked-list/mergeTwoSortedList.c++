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

Node *solve(Node *first, Node *second){
    Node *head = first;
    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;
    Node *next2 = curr2->next;
    while(next1 != NULL && curr2 != NULL){
        if( (curr2->data >=curr1->data) && (curr2->data <= next1->data) ){
            curr1->next= curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // increment curr1 and next1
            curr1 = next1;
            next1 = next1->next;
            if(curr1->next == NULL){
                curr1->next = curr2;
                return head;
            }

        }
    }
    return head;
}

Node *merge(Node *head1, Node *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data < head2->data){
        return solve(head1, head2);
    }
    else{
        return solve(head2,head1);
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
    Node *head = new Node(1);
    Node *second = new Node(4);
    Node *third = new Node(6);
    Node *fourth = new Node(7);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    Node *head2 = new Node(3);
    Node *second2 = new Node(5);
    Node *third2 = new Node(6);

    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;
    Node *list = merge(head,head2);
    traverse(list);





}