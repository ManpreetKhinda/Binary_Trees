#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> traversal;
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
vector<int> preorder(Node*root){
    if(!root) return {};
    vector<int> preorder;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        preorder.push_back(root->data);
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
    return preorder;
}
vector<int> inorder(Node*root){
    stack<Node*> st;
    Node*node=root;
    vector<int> inorder;
    while(1){
        if(node){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty())break;
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    return inorder;
}
vector<int> postorder2stack(Node*root){
    if(root==NULL)return {};
    vector<int> postorder;
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root);
        if(root->left!=NULL)s1.push(root->left);
        if(root->right!=NULL)s1.push(root->right);
    }
    while(!s2.empty()){
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}
vector<int> postorder1stack(Node*root){
    stack<Node*> st;
    vector<int> postorder;
    Node*curr=root;
    Node*temp=NULL;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            temp=st.top()->right;
            if(!temp){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else curr=temp;
        }
    }
}
vector<int> allinone(Node*root){
    stack<pair<Node*,int>>st;
    st.push({root,1});
    vector<int> preorder,postorder,inorder;
    if(!root)return;
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }

        }
        else if(it.second==2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else {
            postorder.push_back({it.first->data});
        }
    }
}