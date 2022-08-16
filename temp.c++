#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    
    struct Node* reverse(struct Node* head){
        if(head == NULL || head->next == NULL){
        return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, struct Node* &node){
        if(head == NULL){
            head = node;
            tail = head;
            delete node;
        }
        else{
            tail->next = node;
            tail = node;
            delete node;
        }
    }

    struct Node* add(struct Node* first, struct Node* second){
        Node *ans = NULL;
        Node *ansHead = ans;
        Node *ansTail = ans;
        int carry = 0;
        
        while(first != NULL || second != NULL || carry != 0){
          
        int val1 = 0;
        int val2 = 0;
        
        if(first!= NULL)
            val1 = first->data;
        if(second != NULL){
            val2 = second->data;
        }
          
        int sum = val1+val2+carry;
        int digit = sum%10;
        Node *temp = new Node(digit);
        insertAtTail(ansHead,ansTail,temp);
        carry = sum/10;
        
        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
        }
        return ansHead;
        
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        
        Node *ans = add(first,second);
        
        ans = reverse(ans);
        
        return ans;
    }
    void traverse(struct Node *head){
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main()
{
    Node *head1 = new Node(4);
    Node *second1 = new Node(5);
    head1->next = second1;
    second1->next = NULL;

    Node *head2 = new Node(2);
    Node *second2 = new Node(4);
    Node *third2 = new Node(5);

    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;

    Solution s1;
    Node *ans = s1.addTwoLists(head1,head2);
    s1.traverse(ans);





}

