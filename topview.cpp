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
void fillmap(Node*root, int d, int l, map<int,pair<int ,int>> &m){
    if(root==NULL){
        return;
    }
    if(m.count(d)==0){
        m[d]=make_pair(root->data,l);
    }
    else if(m[d].second>l){
        m[d]=make_pair(root->data,l);
    }
    fillmap(root->left,d-1,l+1,m);
    fillmap(root->right,d+1,l+1,m);
}
void topview(Node*root){
    map<int,pair<int,int>> m;
    fillmap(root,0,0,m);
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->second.first;
    }
}
vector<int> topView(Node*root){
    if(!root)return{};
    vector<int> ans;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node*node=it.first;
        int line=it.second;
        if(m.find(line)==m.end())m[line]=node->data;
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
}