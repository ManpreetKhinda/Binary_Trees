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
#include <stack>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data =val;
        left=NULL;
        right=NULL;
    }
};
/*
given a binary tree, flatten it into linked list in place
after flattening left of each node should point ot null and right should
contain next node in preorder sequence
recursively flatten the left and right subtree
store the left and right tail
store right subtree in temp &make left subtree as right subtree
join right subtree with left tail
return right tail
*/ 
void flatten(Node*root){
    if(root==NULL||(root->left==NULL &&root->left==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        Node*temp=root->right;
        root->right=root->left;
        root->left=NULL;
        Node*t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatten(root->right);
}
class flattenatree{
    Node*prev=NULL;
    public:
    void flatten2(Node*root){
        if(!root)return ;
        flatten2(root->right);flatten2(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
/*iterative*/
void flatten2(Node*root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node*curr=st.top();st.pop();
        if(curr->right)st.push(curr->right);
        if(curr->left)st.push(curr->left);
        if(!st.empty())curr->right=st.top();
        curr->left=NULL;
    }
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node*root=new Node(10);
    root->left=new Node(8);
    root->right= new Node(12);
    root->left->left=new Node(3);
    // root->left->right=new Node(3);
    // root->right->left=new Node(6);
    // root->right->right=new Node(6);
    flatten2(root);
    inorder(root);
    return 0;
}