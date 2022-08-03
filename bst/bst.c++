#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insertIntoBst(Node* &root, int d)
{
    if (root == NULL)
    {
        Node *node = new Node(d);
        root = node;
        return;
    }
    if (d > root->data)
    {
        insertIntoBst(root->right, d);
    }
    else
    {
        insertIntoBst(root->left, d);
    }
}

// Traversing using level order traversal
void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->data << " ";
    }
    if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        cout << endl;
    }
}

void preOrderTraversal(Node *root){
    if(root == NULL) return;
    cout << root->data << " " ;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// finding minimum element in bst
int min(Node *root){
    Node *temp = root;
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL){
        return root->data;
    }
    return min(root->left);
}

int max(Node *root){
    if(root == NULL){
        return 0;
    }
    if(root->right == NULL){
        return root->data;
    }
    return max(root->right);
}

// deletion 

    //     10               5
    //    /  \             / 
    //   5    15          4  
    //  / \    
    // 4    6
    //        \
    //          9    


Node *deleteFromBst(Node *root, int value){
    if(root == NULL){
        return root;
    }
    if(root->data == value){
        if(root->left == NULL && root->right == NULL){
           // Node *temp =  root;
            delete root;
            return NULL;
        }
        if(root->left == NULL && root->right != NULL){
            Node *temp =  root->right;
            delete root;
            return temp;

        }
        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int mini = min(root->right);
            root->data = mini;
            root->right = deleteFromBst(root->right,mini);
            return root;
        }
    }
    else if(value < root->data){
        root->left =  deleteFromBst(root->left,value);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right,value);
        return root;
    } 

}

int main()
{
    Node *root = NULL;
    int n;
    cout << "Insert Input and press -1 if you want to exit" << endl;
    while (n != -1)
    {
        cin >> n;
        if(n == -1){
            break;
        }
        insertIntoBst(root, n);
    } 
    cout << "Your Tree is look like this" << endl;
    printLevelOrder(root);
    // cout << "preorder" << endl;
    // preOrderTraversal(root);
    // cout << "Minimum element in bst" << endl;
    // cout << min(root) << endl;
    // cout << "Maximum element in bst" << endl;
    // cout << max(root) << endl;
    cout << "Deleting form bast" << endl;
    int delKey;
    cin >> delKey;
    root = deleteFromBst(root,delKey);
    cout << endl;
    cout << "Level order traversal " << endl;
    printLevelOrder(root);

}


//  2  5 9 10 13 15 19

