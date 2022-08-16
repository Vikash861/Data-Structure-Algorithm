#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

vector<int> pairSum(Node *head, int sum){
    vector<int>ans;
    Node *tempPtr = head;
    while(tempPtr->next != NULL){
        tempPtr = tempPtr->next;
    }
    Node * startPtr = head;
    Node *endPtr = tempPtr;

    while(startPtr->data <= endPtr->data){
        if( (startPtr->data + endPtr->data) == sum ){
            ans.push_back(-1);
            ans.push_back(startPtr->data);
            ans.push_back(endPtr->data);
            ans.push_back(-1);
            startPtr = startPtr->next;
            endPtr = endPtr->prev;
        }
        else if((startPtr->data + endPtr->data) < sum){
            startPtr = startPtr->next;
        }
        else{
            endPtr = endPtr->prev;
        }
    }

    return ans;
    
}

int main(){
    Node *head = new Node(1);
    Node *first = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(4);
    Node *fourth = new Node(5);
    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    vector<int>ans = pairSum(head,7);
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }


}