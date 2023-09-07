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


void ancestorarray(Node*root, int ancestor[]){
    ancestor[root->data]=-1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node*t=q.front();
        q.pop();
        if(t->left){
            ancestor[t->left->data]=t->data;
            q.push(t->left);
        }
        if(t->right){
            ancestor[t->right->data]=t->data;
            q.push(t->right);
        }

    }
}
int kthancestor(Node*root, int n,int k,int node){
    int ancestor[n+1]={0};
    ancestorarray(root, ancestor);
    int count=0;
    while(node!=-1){
        node=ancestor[node];
        count++;
        if(count==k){
            break;
        }
    }
    return node;
}
/*
method 2
*/

bool ancestor(Node*root, int item, int &k){
    if(root==NULL){
        return false;
    }
    if(root->data==item){
        k=k-1;
        return true;
    }
    else{
        bool flag=ancestor(root->left,item,k);
        if(flag){
            if(k==0){
                cout<<root->data;
                return false;
            }
            k=k-1;
            return true;
        }
        bool flag2=ancestor(root->right,item,k);
        if(flag2){
            if(k==0){
                cout<<root->data;
                return false;
            }
            k=k-1;
            return true;
        }
    }
}
/*
method 3*/
int kthancestor(Node*root, int node, int k){
    stack<Node*> s;
    vector<int> ancestor;
    bool found=false;
    while(root!=NULL||!s.empty()){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else{
            Node*temp=s.top();
            s.pop();
            if(temp->data==node){
                found=true;
                break;
            }
            if(temp->right!=NULL){
                root=temp->right;
            }
        }
    }
    if(!found){
        return -1;
    }
    while(!s.empty() && k>0){
        Node*t=s.top();
        s.pop();
        ancestor.push_back(t->data);
        k--;
    }
    if(k>0){
        return -1;
    }
    return ancestor.back();

}
/*
method4
*/
Node*temp=NULL;
Node*kthancestor4(Node*root, int node, int &k){
    if(!root){
        return NULL;
    }
    if(root->data==node||(temp=kthancestor4(root->left,node,k))||(temp=kthancestor4(root->right,node,k))){
        if(k>0){
            k--;
        }
        else if(k==0){
            cout<<root->data;
            return NULL;
        }
        return root;
        

    }

}
