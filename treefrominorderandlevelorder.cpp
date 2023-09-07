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
int search(int arr[], int start, int end, int value){
    for(int i=start;i<=end;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}
int *extractkeys(int in[], int level[], int m,int n){
    int *newlevel=new int[m], j=0;
    for(int i=0;i<n;i++){
        if(search(in,0,m-1,level[i]!=-1)){
            newlevel[j]=level[i],j++;
        }
    }
    return newlevel;
}
Node*buildtree(int in[], int level[], int istart, int iend, int n){
    if(istart>iend){
        return NULL;
    }
    Node*root=new Node(level[0]);
    if(istart==iend){
        return root;
    }
    int inIndex=search(in, istart, iend,root->data);
    int *llevel=extractkeys(in, level, inIndex,n);
    int *rlevel=extractkeys(in+inIndex+1, level,n-1,n);
    root->left=buildtree(in,llevel,istart,inIndex-1,inIndex-istart);
    root->right=buildtree(in,rlevel,inIndex+1,iend,iend-inIndex);

    delete[]llevel;
    delete[]rlevel;
    return root;
}
/* using set*/
Node*buildTree(int in[], int level[], int istart, int iend, int n){
    if(n<=0){
        return NULL;
    }
    Node*root=new Node(level[0]);
    int index=-1;
    for(int i=istart;i<=iend;i++){
        if(level[0]==in[i]){
            index=i;
            break;
        }
    }
    unordered_set<int>  s;
    for(int i=istart;i<index;i++){
        s.insert(in[i]);
    }
    int llevel[s.size()];
    int rlevel[iend-istart-s.size()];
    int li=0,ri=0;
    for(int i=1;i<n;i++){
        if(s.find(level[i])!=s.end()){
            llevel[li++]=level[i];
        }
        else{
            rlevel[ri++]=level[i];
        }
    }
    root->left=buildTree(in,llevel,istart,index-1,index-istart);
    root->right=buildTree(in, rlevel,index+1,iend,iend-index);
    return root;
}
/*
using map*/
map<int,int>mp;
void construct(int level[],int n){
    for(int i=0;i<n;i++){
        mp[level[i]]=i;
    }
}
Node*construct(int in[], int start, int end){
    if(start>end){
        return NULL;
    }
    int min_ind=start;
    for(int i=start+1;i<=end;i++){
        int temp=in[i];
        if(mp[in[min_ind]]>mp[temp]){
            min_ind=i;
        }
    }
    Node*root =new Node(in[min_ind]);
    if(start==end){
        return root;
    }
    root->left=construct(in,start,min_ind-1);
    root->right=construct(in,min_ind+1,end);
    return root;
}
/*using queue*/
Node* buildTree(int inorder[], int levelOrder[], int iStart,
                int iEnd, int n)
{
    queue<pair<Node*, pair<int, int> > > q;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;
    int idx = 0;
    Node* root = new Node(levelOrder[idx++]);
    q.push({ root, { 0, n - 1 } });
    while (!q.empty()) {
        int m = q.size();
        for (int i = 0; i < m; i++) {
            auto p = q.front();
            q.pop();
            int leftEnd = mp[p.first->data] - 1;
            int rightStart = mp[p.first->data] + 1;
            // check if nodes to added into the left part of
            // q.front()
            if (p.second.first <= leftEnd) {
                p.first->left = new Node(levelOrder[idx++]);
                q.push({ p.first->left,
                         { p.second.first, leftEnd } });
            }
            // check if nodes to added into the right part
            // of q.front()
            if (rightStart <= p.second.second) {
                p.first->right
                    = new Node(levelOrder[idx++]);
                q.push({ p.first->right,
                         { rightStart, p.second.second } });
            }
        }
    }
    return root;
}