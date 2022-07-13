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

int helper(node *root){
    int height;
    if(root == NULL){
        return 0;
    }
    int left = helper(root->left);
    int right = helper(root->right);
    return max(left,right) + 1;
}

int height(node *root){
    return helper(root);
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

    int ht = height(root);
    cout << ht << endl;

    bool diff = 4 - 2 <= 5;
    cout << diff << endl;

}



