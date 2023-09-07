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
void levelorder(Node*root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
vector<vector<int>> levelorderlist(Node*root){
    if(root==NULL){
        return;
    }
    vector<vector<int>> traversal;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int depth=0;
    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(node!=NULL){
            traversal[depth].push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            depth++;
        }
    }
    return traversal;
}
// int main(){
//     Node*root=new Node(1);
//     root->left=new Node(2);
//     root->right= new Node(3);
//     root->left->left=new Node(4);
//     root->left->right=new Node(5);
//     root->right->left=new Node(6);
//     root->right->right=new Node(7);
//     levelorder(root);
// }
////sum of nodes at kth level
int sumatK(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right= new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<sumatK(root,2);
}
/*
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        vector<int> tempo={};
        if(root==NULL){
           return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            // TreeNode*temp=q.front();
            // q.pop();
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();
                tempo.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            traversal.push_back(tempo);
            tempo.clear();
        }
        return traversal; 
    }
*/