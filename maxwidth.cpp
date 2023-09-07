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
int widthofbinarytree(Node*root){
    if(!root)return 0;
    int ans=0;
    queue<pair<Node*,int>> q;q.push({root,0});
    while(!q.empty()){
        int n=q.size();
        int minindex=q.front().second;
        int first,last;
        for(int i=0;i<n;i++){
            int currindex=q.front().second-minindex;
            Node*curr=q.front().first;
            q.pop();
            if(i==0)first=currindex;
            if(i==n-1)last=currindex;
            if(curr->left)q.push({curr->left,2*currindex+1});
            if(curr->right)q.push({curr->right,2*currindex+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;

}