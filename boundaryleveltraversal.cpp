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

void printleaves(Node*root){
    if(root==NULL){
        return;
    }
    
    printleaves(root->left);
    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
    }
    printleaves(root->right);
}

void printboundaryleft(Node*root){
    if(root==NULL){
        return ;
    }
    if(root->left){
        /*
        here top down order is required hence value is printed before
        another recursive call*/
        cout<<root->data<<" ";
        printboundaryleft(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printboundaryleft(root->right);
    }
}

void printboundaryright(Node*root){
    if(root==NULL){
        return;
    }
    if(root->right){
        printboundaryright(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printboundaryright(root->left);
        cout<<root->data<<" ";
    }
}

void printboundary(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printboundaryleft(root->left);
    printleaves(root->left);
    printleaves(root->right);
    printboundaryright(root->right);
}
/*iterative method*/
bool isLeaf(Node*root){
    if(!(root->left) &&!(root->right)){
        return true;
    }
    return false;
}
void addleft(Node*root, vector<int> &ans){
    root=root->left;
    while(root){
        if(!isLeaf(root))ans.push_back(root->data);
        if(root->left)root=root->left;
        else root=root->right;
    }
}
void addright(Node*root, vector<int> &ans){
    root=root->right;
    stack<int> st;
    while(root){
        if(!isLeaf(root))st.push(root->data);
        if(root->right)root=root->right;
        else root=root->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
void addleaves(Node*root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    addleaves(root->left,ans);
    addleaves(root->right,ans);
}
vector<int> boundarytraversal(Node*root){
    vector<int> ans;
    if(root==NULL)return ans;
    if(!isLeaf(root))ans.push_back(root->data);
    addleft(root,ans);
    addleaves(root,ans);
    addright(root,ans);
    return ans;
}
