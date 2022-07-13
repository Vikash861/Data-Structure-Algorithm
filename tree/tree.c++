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

/*
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
*/

// level order traversal 


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

int height(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
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
    node *root = new node(1);
    node *left = new node(2);
    node *right = new node(3);
    root->left = left;
    root->right= right;
    left->left = new node(5);
    right->right = new node(6);

    // root = buildTree(root);
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    printLevelOrder(root);

    // cout << "pre order traveral" << endl;
    // preOrderTraversal(root);
    // cout << "\nIn order traversal" << endl;
    // inOrderTraversal(root);
    // cout << "\n post order traversal" << endl;
    // postOrderTraversal(root);

    
}