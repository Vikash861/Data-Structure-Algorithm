#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next; // this is pointer it will store address of next object
};

// for creation of a node
node *create(int data) // this a pinter type of function bcz it will return pinter node
{
    node *n = new node();
    n->data = data;
    n->next = NULL;
    return n;
}


void insertAtTail(node *&tail, int data)
{
    node *n = create(data);
    tail->next = n;
    tail = n;
}


void traverse(node *head)
{
    // head -- copy poiter 
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}


/////////////////////////////////////////////LINKED LIST CREATION////////////////////////////////////////

node *createList(){
    int num;
    cout << "Number of element for list :";
    cin >> num;
    int data;
    cout << "Enter Data: ";
    cin>>data;
    node *list = create(data);
    node *head = list;
    int cnt = 1;
    while(cnt < num){
        cout << "Enter Data: ";
        cin>>data;
        insertAtTail(list,data);
        cnt++;
    }
    return head;
}
////////////////// n = number of element ////////////////////////////////////


/////////////////////////// REVERSE A LINKED LIST ////////////////////////////

node *reverse(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
/////////////////////////////////////////////////////////////// REVERSED LINKED LIST USING RECURSION /////////////////////////////////////////////

void helper(node *&curr, node *&prev,node *&forward){
    if(curr == NULL){
        return;
    }
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    helper(curr,prev,forward);
}

node *reverse2(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    helper(curr,prev,forward);
    return prev;

}

bool circularOrNot(node *head){
    node *temp = head;
    if(head==NULL){
        return false;
    }
    head = head->next;
    if(head == temp){
        return true;
    }
    while(1){
        if(head == temp){
            return true;
        }
        else{
            if(head == NULL){
                return false;
            }
            head = head->next;
        }
    }
    return false;
}

int main()
{
    node *list = createList();
    // traverse(list);
    // cout << "///////////////////////////////////////////////////////////////LIST AFTER REVERSED/////////////////////////////////////////////////////////////"<< endl;

    // // node *head = reverse(list);
    // node *head = reverse2(list);
    // traverse(head);

    if(circularOrNot(list)){
        cout << "list is circular" << endl;
    }
    else{
        cout << "list is not cicular" << endl;
    }

}