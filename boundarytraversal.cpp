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
bool isleaf(Node* root){
    if(!root->left && !root->right)return true;
    return false;
}
void addleftboundary(Node*root, vector<int>&res){
    Node*curr=root->left;
    while(curr){
        if(!isleaf(curr))res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}
void addrightboundary(Node*root, vector<int>&res){
    Node*curr=root->right;
    stack<int> temp;
    while(curr){
        if(!isleaf(curr))temp.push(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    while(!temp.empty()){
        int a=temp.top();temp.pop();
        res.push_back(a);
    }
}
void addleaves(Node*root,vector<int>&res){
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left)addleaves(root->left,res);
    if(root->right)addleaves(root->right,res);
}
vector<int> printboundary(Node*root){
    vector<int>res;
    if(!root)return res;
    if(!isleaf(root))res.push_back(root->data);
    addleftboundary(root,res);
    addleaves(root,res);
    addrightboundary(root,res);
    return res;
}
