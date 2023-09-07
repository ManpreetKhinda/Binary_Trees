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
/* this traversal is valid if there are multiple nodes passing
through a vertical line then they are to be printed as they 
appear in lot*/
vector<int> verticalorder(Node*root){
    if(!root)return{};
    queue<pair<Node*,int>> q;
    vector<int> ans;
    q.push({root,0});
    map<int,vector<int>>m;
    while(!q.empty()){
        auto x=q.front();q.pop();
        Node*temp=x.first;
        int val=x.second;
        m[val].push_back(temp->data);
        if(temp->left)q.push({temp->left,val-1});
        if(temp->right)q.push({temp->right,val+1});
    }
    for(auto i:m){
        vector<int> t=i.second;
        ans.insert(ans.end(),t.begin(),t.end());
    }
}

/*if there are multiple value at same horizonatal level
and are to be sorted*/
vector<vector<int>> vot(Node*root){
    map<int,map<int,multiset<int>>>m;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();q.pop();
        Node*curr=p.first;
        int x=p.second.first,y=p.second.second;
        m[x][y].insert(curr->data);
        if(curr->left)q.push({curr->left,{x-1,y+1}});
        if(curr->right)q.push({curr->right,{x+1,y+1}});
    }
    vector<vector<int>>ans;
    for(auto p:m){
        vector<int> col;
        for(auto i:p.second){
            col.insert(col.end(),i.second.begin(),i.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}