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

Node *interSection(Node *head1, Node *head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    Node *ans = new Node(-1);
    Node *returnAns = ans;

    Node *list1Head = head1;

    while(list1Head != NULL){
        Node *list2Head = head2;
        while(list2Head != NULL){
            if(list2Head->data == list1Head->data){
                ans->next = new Node(list2Head->data);
                ans = ans->next;
                list2Head = list2Head->next;
            }
            else{
                list2Head = list2Head->next;
            }
        }
        list1Head = list1Head->next;
    }
    return returnAns->next;
}

int main(){
    Node *head1 = new Node(1);
    // Node *second1 = new Node(10);
    // Node *third1 = new Node(30);
    // Node *fourth1 = new Node(35);
    // Node *fifth1 = new Node(40);
    // head1->next = second1;
    // second1->next = third1;
    // third1->next = fourth1;
    // fourth1->next = fifth1;
    head1->next =  NULL;

    Node *head2 = new Node(1);
    // Node *second2 = new Node(60);
    // Node *third2 = new Node(30);

    // head2->next = second2;
    // second2->next = third2;
    head2->next = NULL;


    Node *ansList = interSection(head1,head2);
    traverse(ansList);



}