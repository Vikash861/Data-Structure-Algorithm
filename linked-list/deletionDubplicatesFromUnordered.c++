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


void removeDuplicates(Node * curr){
    while(curr != NULL){
        Node *temp = curr->next;
        Node *prev = curr;
        while(temp != NULL){
            if(curr->data == temp->data){
                Node *delNode = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete(delNode);
            }
            else{
                temp = temp->next;
                prev = prev->next;
            }
        
        }
        curr = curr->next;
    }
}

// using map

void removeDuplicates2(Node *head){
    map<Node *, bool>visited;
    Node *curr = head;
    while(curr != NULL){
        auto it = visited.find(curr);
        if((*it).second == true){
            cout << ("i am in")<< endl;
            Node *temp = curr;
            curr->next = curr->next->next;
            delete(temp);
        }
        else{
            visited[curr] = true;
        }
        curr = curr->next;
        

    }
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
    Node *second = new Node(20);
    Node *third = new Node(10);
    Node *fourth = new Node(60);
    Node *fifth = new Node(20);
    Node *tail = new Node(30);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail;
    tail->next = NULL;
    traverse(head);
    cout << endl;
    cout << "LIST AFTER DELETION " << endl;
    removeDuplicates2(head);
    traverse(head);

}