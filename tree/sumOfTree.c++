#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


//           10          |          3
//         /    \        |         / \   
//       20      30      |        1   2  
//     /   \             | 
//    10    10           |                

pair<bool,int>solve(Node *root){
    if(root == NULL){
        pair<bool,int>p;
        p.first = true;
        p.second = 0;
        return p;
    }
    
    if(root->left == NULL && root -> right == NULL){
        pair<bool,int>p;
        p.first = true;
        p.second = root->data;
        return p;
    }
    pair<bool,int>left = solve(root->left);
    pair<bool,int>right = solve(root->right);
    int sum = left.second + right.second;
    pair<bool,int>ans;
    if(sum == root->data && left.first && right.first){
        ans.first = true;
        ans.second = root->data + sum;
    }
    else{
        ans.first = false;
    }
    return ans;

    
}

bool isSumTree(Node *root)
{
    pair<bool,int>ans = solve(root);
    cout << ans.second << endl;
    return ans.first;
}

int main(){
    Node *root = new Node(3);
    Node *left = new Node(1);
    Node *right = new Node(2);
    root->left = left;
    root->right= right;
    // left->left = new Node(5);
    // right->right = new Node(6);
    if(isSumTree(root)){
        cout << "Sum Tree" << endl;
    }
    else{
        cout << "not a sum tree" << endl;
    }
}




     
