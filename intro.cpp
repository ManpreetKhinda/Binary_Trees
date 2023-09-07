/* properties of binary tress
max nodes at L level=2^L
max nodes in a tree= 2^h-1
for n nodes minlevels=log(n+1)
with l leaves ha s at least log(n+1) levels

*/
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> traversal;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int toSumTree(Node *node)
{
    // Base case
    if (node == NULL)
        return 0;

    // Store the old value
    int old_val = node->data;

    // Recursively call for left and
    // right subtrees and store the sum as
    // old value of this node
    node->data = toSumTree(node->left) + toSumTree(node->right);

    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return node->data + old_val;
}
int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->right->left = new Node(10);
    root->right->right = new Node(11);

    // toSumTree(root);
    inorder(root);
}

/* preorder traversal
root value
left subtree
right subtree
*/
/*inorder
left
root
right*/
/*postorder
left
right
root*/
class solution{
    public:
    bool flag=1;
    int tosumtree(Node*root){
        if(!root)return 0;
        int l=tosumtree(root->left);
        int r=tosumtree(root->right);
        if(!root->left && !root->right){
            return root->data;
        }
        if(root->data!=(l+r)){
            flag=false;
        }
        return l+r+root->data;
    }
    bool issumtree(Node*root){
        flag=true;
        tosumtree(root);
        return flag;
    }
};