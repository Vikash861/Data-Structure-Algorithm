#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};


void morisTraversal(Node *root){
    Node *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            Node *pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }

    } 
}

int main() {

    Node *root = new Node(1);
    Node *left = new Node(2);
    Node *right = new Node(3);
    Node *third = new Node(4);
    Node *fourth = new Node(5);
    root->left = left;
    left->left = third;
    left->right = fourth;
    root->right = right;
    morisTraversal(root);


    return 0;
}