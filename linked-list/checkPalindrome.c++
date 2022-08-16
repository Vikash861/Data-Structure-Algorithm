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


void helper(Node *&curr, Node *&prev,Node *&forward){
    if(curr == NULL){
        return;
    }
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    helper(curr,prev,forward);
}

Node *reverse2(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    helper(curr,prev,forward);
    return prev;

}
bool checkPalindrome(Node *head){
    if(head == NULL){
        return false;
    }
    vector<int>v;
    while(head != NULL){
        v.push_back(head->data);
        head = head->next;
    }
    int s = 0;
    int e = v.size()-1;
    while(s<=e){
        if( v[s++] != v[e--] ){
            return false;
        }
    
    }
    // for(int i=0; i<v.size(); i++){
    //     cout << v[i] << endl;
    // }
    return true;
}

void traverse(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
bool checkPalindrome2(Node *head){
    Node *cntHead = head;
    Node *revHead = head;
    Node *curr = head;
    int cnt = 0;  
    while(cntHead != NULL){
        cntHead = cntHead->next;
        cnt++;
    }
    int mid = cnt/2;
    cnt  = 0;
    while(cnt < mid){
        revHead = revHead->next;
        cnt++;
    }
    Node *revList = reverse2(revHead);
    while(curr != revHead && revList != NULL){
        if(curr->data != revList->data){
            return false;
        }
        curr = curr->next;
        revList = revList->next;
    }
    return true;
}




int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    // Node *third = new Node(3);
    // Node *fourth = new Node(1);
    head->next = second;
    second->next = NULL;
    // third->next = fourth;
    // fourth->next = NULL;
    // cout << checkPalindrome2(head) << endl;
    if(checkPalindrome2(head))
        cout << "list is Palindrome" << endl;
    else
        cout << "list is not a palindrome" << endl;


}  