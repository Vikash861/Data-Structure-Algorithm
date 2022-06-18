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
// 500 19 22 50 

int main(){
    node *head = create(19);
    // cout << head->next << endl;
    insetionAtPosition(head,2,22);
    insetionAtPosition(head,3,50);
    insetionAtPosition(head,1,500);
    insetionAtPosition(head,3,599);
    cout << "Value delete is: " <<deletionByPosition(head,1) << endl;
    cout << "deleted value is : " <<deletionByPosition(head,4) << endl;
    traverse(head);
    cout << endl <<"Head: " << head->data << endl;
}