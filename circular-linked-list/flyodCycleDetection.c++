#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "the value deleted is: " << value << endl;
    }
};

void traverse(Node *tail)
{
    if (tail == NULL)
    {
        cout << "there is nothing to print in linked list" << endl;
        return;
    }
    Node *curr = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != curr);
    cout << endl;
}

void insertion(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        // new Node
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
        return;
    }

    Node *curr = tail;
    while (element != curr->data)
    {
        curr = curr->next;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
    // tail = temp;
}

void deletion(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List doesn't have element to delete";
        return;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != value)
    {
        prev = prev->next;
        curr = curr->next;
    }

    prev->next = curr->next;

    if (curr == prev)
    {
        tail = NULL;
    }

    else if (tail == curr)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}
// 1 2 3 

bool cycleOrNot(Node *head){
    if(head == NULL){
        return false;
    }
    Node* slow = head;
    Node *fast = head;
    while(1){
        fast = fast->next;
        if(fast == slow){
            return true;
        }
        if(fast->next != NULL){
            fast = fast->next;
        }
        else{
            return false;
        }
        slow = slow->next;
    }
    return false;
}

// 10 50 30 100

int main()
{
    // empty
    Node *tail = NULL;
    insertion(tail, 0, 10);
    insertion(tail, 10, 30);
    insertion(tail, 10, 50);
    insertion(tail, 30, 100);
    traverse (tail);
    // if(circularOrNot(tail)){
    //     cout << "list is circular" << endl;
    // }
    // else{
    //     cout << "list is not cicular" << endl;
    // }
    if(cycleOrNot(tail)){
        cout << "Cycle is present" << endl;
    }
    else{
        cout << "Cycle is not presend" << endl;
    }
}