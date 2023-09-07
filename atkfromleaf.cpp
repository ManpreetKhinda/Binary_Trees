#include <iostream>
#include <cmath>
#include <stack>

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
/*
recursive method*/
#define MAX_HEIGHT 100000
void kdistance(Node*node, int path[],bool visited[], int pathlen, int k){
    if(node==NULL){
        return ;
    }
    path[pathlen]=node->data;
    visited[pathlen]=false;
    pathlen++;
    if(node->left==NULL && node->right==NULL && pathlen-k-1>=0 
    && visited[pathlen-k-1]==false){
        cout<<path[pathlen-k-1]<<" ";
        visited[pathlen-k-1]=true;
        return;
    }
    kdistance(node->left,path,visited,pathlen,k);
    kdistance(node->right,path,visited,pathlen,k);

}
void printkfromleaf(Node*node, int k){
    int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT]={false};
    kdistance(node,path,visited,0,k);
}

/*
iterative approach*/
void printkdis(Node*root, int k){
    stack<pair<Node*,int>> st;
    vector<int> path;
    vector<int>path;
    vector<bool>visited;
    st.push(make_pair(root,0));
    while(!st.empty()){
        pair<Node*,int> curr=st.top();
        st.pop();
        if(curr.first==NULL){
            continue;
        }
        path.push_back(curr.first->data);
        visited.push_back(false);
        if(curr.first->left==NULL && curr.first->right==NULL){
            int depth=path.size()-1-k;
            if(depth>=0 && !visited[depth]){
                cout<<path[depth]<<" ";
                visited[depth]=true;
            }
        }
        st.push(make_pair(curr.first->left,curr.second+1));
        st.push(make_pair(curr.first->right,curr.second+1));

        if(curr.second+1<path.size()){
            path.resize(curr.second+1);
            visited.resize(curr.second+1);
        }
    }
}