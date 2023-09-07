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

vector<int> reverseLevelOrder(Node*root){
    vector<int> rlot;
    if(root==NULL){
        return {};
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*t=q.front();
        q.pop();
        if(t!=NULL){
            rlot.push_back(t->data);
        
            if(t->right){
            q.push(t->right);
            // rlot.push_back(t->right->data);
            }
            if(t->left){
            q.push(t->left);
            // rlot.push_back(t->left->data);
            }
        }
        if(!q.empty()){
            q.push(NULL);
        }
        
    }
    reverse(rlot.begin(),rlot.end());
    return rlot;
}