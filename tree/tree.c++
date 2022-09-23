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


node *buildTree(node *root){
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    if(data == -1){// enter this value to set -1;
        return NULL;
    }
    root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// finding height of tree

int height(node* node)
{
    if (node == NULL)
        return 0;

    /* compute the height of each subtree */
    int lheight = height(node->left);
    int rheight = height(node->right);
    int maxHeight = max(lheight,rheight) + 1;
    return maxHeight;
}

// level order traversal 

/*
void printCurrentLevel(node *root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << " ";
    }
    if(level > 1){
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
        printCurrentLevel(root, i);
        cout << endl;
    }
}
*/


// level order traversal using queue

void levelOrderTraversal(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp->right);
            }
        }
    }
}

// preorder Traversal

void preOrderTraversal(node *root){
    if(root == NULL) return;
    cout << root->data << " " ;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// inorder Traversal
void inOrderTraversal(node *root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// postorder traversal 
void postOrderTraversal(node *root){
    if(root == NULL){
        return;
    }
   postOrderTraversal(root->left);
   postOrderTraversal(root->right);
   cout << root->data << " " ;
}


int main()
{
    node *root = new node(10);
    root->left = new node(50);
    root->right = new node(60);
    root->left->left = new node(76);
    root->right->left = new node(90);
    levelOrderTraversal(root);
}