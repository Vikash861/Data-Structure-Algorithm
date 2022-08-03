#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    node *prev;
    int data;
    node *next;
};

void traverse(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

node *create(int data){
    node *n = new node;
    n->prev = NULL;
    n->next = NULL;
    n->data = data;
    return n;
}

void insetionAtPosition(node *&head,int pos, int data){
    if(pos == 1){
        node *n = create(data);
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }

    node *temp = head;
    node *n = create(data);
    int cnt = 1;
    while (cnt < pos-1) //2 < 2
    {
        temp = temp->next;
        cnt++;
    }
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;

}

// Deletion in linked list 
int deletionByPosition(node *&head, int pos){
    if(pos == 1){
        node *temp = head;
        int value = temp->data;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return value;
    }
    // node *temp = head;
    node *pre= NULL;
    node *curr = head;
    int cnt = 1;
    while(cnt < pos){
    pre = curr;
    curr = curr->next;
    cnt++;
    }
    curr->prev = NULL;
    pre->next = curr->next;
    curr->next = NULL;
    int value = curr->data;
    delete curr;
    return value;
}

///////////////////////////////////////////////////////////// REVERSE OF LINKED LIST ///////////////////////////////////////
node *reverse(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *ptr = NULL;

    while(head->next != NULL){
        head = head->next;
    }
    ptr = head->prev;
    return ptr;
}

int main(){
    node *head = create(19);
    insetionAtPosition(head,2,22);
    insetionAtPosition(head,3,50);
    insetionAtPosition(head,4,500);
    insetionAtPosition(head,5,599);
    cout << "///////////////////LIST BEFORE REVERSED/////////////////////"<< endl;
    traverse(head);
    node *revPtr = reverse(head);
    cout << "///////////////////LIST AFTER REVERSED/////////////////////"<< endl;
    traverse(revPtr);
}