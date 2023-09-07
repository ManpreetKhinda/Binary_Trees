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
void fillmap(Node*root,int v, int h, map<int, pair<int,int>> &m){
        if(root==NULL){
            return;
        }
        if(m.count(v)==0){
            m[v]=make_pair(root->data,h);
        }
        if(m[v].second<=h){
            m[v]=make_pair(root->data,h);
        }
        fillmap(root->left,v-1, h+1,m);
        fillmap(root->right,v+1,h+1,m);
}
vector<int> bottomView(Node*root){
    vector<int> ans;
    map<int,pair<int,int>> m;
    fillmap(root,0,0,m);
    for(auto it=m.begin();it!=m.end();it++){
        ans.push_back(it->second.first);
    }
    return ans;
}

vector<int> bottomview(Node*root){
    if(!root)return {};
    vector<int> ans;
    queue<pair<Node*,int>>q;
    map<int,int>m;
    q.push({root,0});
    while(!q.empty()){
        auto i=q.front(); q.pop();
        Node*curr=i.first;
        int x=i.second;
        m[x]=curr->data;
        if(curr->left)q.push({curr->left,x-1});
        if(curr->right)q.push({curr->right,x+1});
    }
    for(auto i:m)ans.push_back(i.second);
    return ans;
}