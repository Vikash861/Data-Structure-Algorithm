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

// 1 2

/////////////////////////// MIDDLE ELEMENT OF LINKED LIST USING FAST AND SLOW POINTER ////////////////////////////

node *middle(node *head){
    if(head == NULL || head ->next == NULL){
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
//////////////////////////////////////////////TIME COMPLEXITY = O(logn)//////////////////////////////////////////////////
////////////////////////////////////////////SPACE COMPLEXITY = O(1)////////////////////////////////////////////

/////////////////////////////////// MIDDLE ELEMENT OF LINKED LIST USING MID //////////////////////////////////////

node *middle2(node *head){
    node *temp = head;
    if(head == NULL || head ->next == NULL){
        return head;
    }
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        cnt++;
    }
    int mid = cnt/2;
    // cout << mid << endl;
    cnt = 0;
    while(cnt < mid){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
/////////////////////TIME COMPLEXITY = O(n)///////////////////////////////////////////////////////
///////////////////////SPACE COMPLEXITY = O(1)////////////////////////////////////////////



int main()
{
    node *list = createList();
    traverse(list);

    // node *Node = middle(list);
    node *Node = middle2(list);
    cout <<"///////////////////////////////////////////////////MIDDLE ELEMENT OF THE LIST///////////////////////////"<< endl;
    cout << Node->data << endl;


}