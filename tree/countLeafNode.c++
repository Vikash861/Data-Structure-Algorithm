#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void helper(node *root, int & count){
    if(root == NULL){
        return;
    }
    helper(root->left,count);
    helper(root->right,count);
    if(root->left == NULL && root->right == NULL){
    count++;
    }
}

int coutLeafNode(node *root){
    int count = 0;
    helper(root,count);
    return count;
}

int main()
{
    node *root = new node(1);
    node *left = new node(2);
    node *right = new node(3);
    root->left = left;
    root->right= right;
    left->left = new node(5);
    right->right = new node(6);

    int leafCount = coutLeafNode(root);
    cout << leafCount << endl;

}