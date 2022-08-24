#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void push(Node *&stackTop, int data){
    Node *temp = new Node(data);
    stackTop->next = temp;
    stackTop = stackTop->next;
}

int main()
{
    Node *stackHead = new Node(10);
    Node *top = stackHead;;
    push(top,20);
    cout << top->data << endl;
}