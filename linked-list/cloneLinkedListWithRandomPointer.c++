#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    private:
        void insertAtTail(Node *&cloneHead, Node *&cloneTail, int val){
            if(cloneHead == NULL){
                Node *temp = new Node(val);
                cloneHead = temp;
                cloneTail = temp;
            }
            else{
            Node *temp = new Node(val);
            cloneTail->next = temp;
            cloneTail = temp;
            }
            
        }
    
    public:
        Node* copyRandomList(Node* head) {
            // edges cases
            if(head == NULL){
                Node *cloneHead = NULL;
                return cloneHead;
            }
            else if(head->next == NULL){
                if(head->random == NULL){
                    Node *cloneHead = new Node(head->val);
                    cloneHead->random = NULL;
                    return cloneHead;
                }
                else if(head->random == head){
                     Node *cloneHead = new Node(head->val);
                     cloneHead->random = cloneHead;
                     return cloneHead;
                }
            }

            // Cloning list 

            Node *cloneHead = NULL;
            Node *cloneTail = NULL;
            
            Node *originalHead = head;
            while(originalHead != NULL){
                int val = originalHead->val;
                insertAtTail(cloneHead,cloneTail,val);
                originalHead = originalHead->next;
            }

            // mapping in original list 

            Node *orginalListNode = head;
            Node *orginalListNodeNext = NULL;
            Node *cloneListNode = cloneHead;
            Node *cloneListNodeNext = NULL;

            while(orginalListNode != NULL){
            orginalListNodeNext = orginalListNode->next;
            orginalListNode->next = cloneListNode;
            orginalListNode = orginalListNodeNext;
            cloneListNodeNext = cloneListNode->next;
            cloneListNode->next = orginalListNode;
            cloneListNode = cloneListNodeNext;
            }

            // cloneListNode.random = originalListNode.random;-Next
            orginalListNode = head;
            cloneListNode = cloneHead;

            while(orginalListNode != NULL && cloneListNode != NULL){
    
                if(orginalListNode->random == NULL){
                    cloneListNode->random = orginalListNode->random;
                    orginalListNode = orginalListNode->next->next;
                    cloneListNode = cloneListNode->next;
                    if(cloneListNode != NULL){
                        cloneListNode = cloneListNode->next;
                    }
                }
                else{
                    cloneListNode->random = orginalListNode->random->next;
                    orginalListNode = orginalListNode->next->next;
                    cloneListNode = cloneListNode->next;
                    if(cloneListNode != NULL){
                        cloneListNode = cloneListNode->next;
                    }
                }

            }

            orginalListNode = head;
            cloneListNode = cloneHead;

            while(orginalListNode != NULL && cloneListNode != NULL){

            orginalListNode->next = cloneListNode->next;
            orginalListNode = cloneListNode->next;
            if(orginalListNode == NULL){;
                cloneListNode = cloneListNode->next;
            }
            else{
                cloneListNode->next = orginalListNode->next;
                cloneListNode = orginalListNode->next;
            }
            }
            

            return cloneHead;
            
            
        }
};

using namespace std;
int main()
{
    Node *first = new Node(7);
    Node *second = new Node(13);
    Node *third = new Node(11);
    Node *fourth = new Node(10);
    Node *fifth = new Node(1);

    first->next = second;
    second->next = third;
    third->next =fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    first->random = fifth->next;
    second->random = first;
    third->random = fifth;
    fourth->random = third;
    fifth->random = first;

    Solution S1;
    Node *ansListHead = S1.copyRandomList(first);

    while(ansListHead != NULL ){
        cout << ansListHead->val << endl;
        ansListHead = ansListHead->next;
    }
}