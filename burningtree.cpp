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
int findmaxdis(map<Node*,Node*>&mp,Node*target){
    queue<Node*> q;
    q.push(target);
    map<Node*,int> vis;
    vis[target]=1;
    int maxi=0;
    while(!q.empty()){
        int sz=q.size();
        int fl=0;
        for(int i=0;i<sz;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left&& !vis[curr->left]){
                fl=1;
                vis[curr->left]=1;
                q.push(curr->left);
            }
            if(curr->right &&! vis[curr->right]){
                fl=1;
                vis[curr->right]=1;
                q.push(curr->right);
            }
            if(mp[curr]&&!vis[mp[curr]]){
                fl=1;
                vis[mp[curr]]=1;
                q.push(mp[curr]);
            }
        }
        if(fl)maxi++;
    } 
    return maxi;
}
Node*bfstomap(Node*root, map<Node*,Node*>&mp, int start){
    queue<Node*> q;
    q.push(root);
    Node*res;
    while(!q.empty()){
        Node*node=q.front();
        if(node->data==start)res=node;
        q.pop();
        if(node->left){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}
int timetoburn(Node*root, int start){
    map<Node*, Node*>mp;
    Node*target=bfstomap(root,mp,start);
    int maxi=findmaxdis(mp,target);
    return maxi;
}