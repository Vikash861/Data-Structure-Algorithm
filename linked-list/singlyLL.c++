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

// insertion at beginning
void insetAtHead(node *&head, int data)
{
    node *n = create(data);
    n->next = head;
    head = n;
}
// insertion in linked list
// insertion at end
void insertAtTail(node *&tail, int data)
{
    node *n = create(data);
    tail->next = n;
    tail = n;
}

// insertion at middle
void insertAtPosition(node *&head, node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        insetAtHead(head, data);
        return;
    }

    node *temp = head;
    node *n = create(data);
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    n->next = temp->next;
    temp->next = n;
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

// deletion in linked list
// deletion at position

int deletionByPosition(node *&head, int pos)
{

    if (pos == 1)
    {
        node *temp = head;
        int tmp = temp->data;
        head = head->next;
        delete temp;
        return tmp;
    }

    int cnt = 1;
    node *prevPtr = head;
    node *ptrNext = head;
    while (cnt < pos - 1)
    {
        ptrNext = ptrNext->next;
        prevPtr = prevPtr->next;
        cnt++;
    }
    // 1 step forward than previous
    ptrNext = ptrNext->next;

    int temp = ptrNext->data;
    prevPtr->next = ptrNext->next;
    delete ptrNext;
    return temp;
}

// deletion by value
void deletionByValue(node *&head, int value)
{
    int cnt = 1;
    node *prevPtr = head;
    node *nextPtr = head;
    while (1)
    {
        if (nextPtr->data == value || head->next == NULL)
        {
            goto done;
        }
        cout << "I am in" << endl;
        nextPtr = nextPtr->next;
        prevPtr = prevPtr->next;
        cnt++;
    }

// for deleting first element
done:
    if (cnt == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    nextPtr = nextPtr->next;
    prevPtr = nextPtr->next;
    nextPtr == NULL;
    delete nextPtr;
}

// 56, 87 ,98 ,87, 87

/////////////////////////////////////////////LINKED LIST CREATION////////////////////////////////////////

node *createList()
{
    int num;
    cout << "Number of element for list :";
    cin >> num;
    int data;
    cout << "Enter Data: ";
    cin >> data;
    node *list = create(data);
    node *head = list;
    int cnt = 1;
    while (cnt < num)
    {
        cout << "Enter Data: ";
        cin >> data;
        insertAtTail(list, data);
        cnt++;
    }
    return head;
}

////////////////// n = number of element ////////////////////////////////////

bool cycleOrNot(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head;
    while (1)
    {
        fast = fast->next;
        if (fast == slow)
        {
            return true;
        }
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        else{
            return false;
        }
        slow = slow->next;
    }
    return false;
}

int main()
{
    /*
    node *n1 = create(18);
    node *head = n1; //this is original pointer
    node *tail = n1;
    // insertions
    insetAtHead(head,20);
    insertAtPosition(head,tail,22,2);
    insertAtTail(tail,30);
    traverse(head);
    cout << "Head :" << head->data <<  " Tail: "  <<tail->data << endl;
    // cout << "deleted value: " << deletionByPosition(head,3) << endl;
    // cout << "deleted value: " << deletionByPosition(head,2) << endl;
    cout << "deleted value: " << deletionByPosition(head,4) << endl;
    cout << "deleted value: " << deletionByPosition(head,3) << endl;
    // deletionByValue(head,18);
    cout << "Head :" << head->data <<  " Tail: "  <<tail->data << endl;
    */
    node *list = createList();
    if (cycleOrNot(list))
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not presend" << endl;
    }
    traverse(list);
}