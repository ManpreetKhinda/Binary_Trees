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
//count nodes
int countnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
//sum of all the nodes
int sumnode(Node*root){
    if(root==NULL){
        return 0;
    }
    return sumnode(root->left)+sumnode(root->right)+root->data;
}
// height of bianry tree
int heightofbt(Node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=heightofbt(root->left);
    int rheight=heightofbt(root->right);
    return max(lheight,rheight)+1;
}

/* count nodes in a complete binary tree on O(<n) */
int findheightleft(Node*root){
    int height=0;
    while(root){
        height++;root=root->left;
    }
    return height;
}
int findheightright(Node*root){
    int height=0;
    while(root){
        height++;root=root->right;
    }
    return height;
}
int countNodes(Node*root){
    if(!root)return 0;
    int lh=findheightleft(root);
    int rh=findheightright(root);
    if(lh==rh)return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}
/*
diameter of a tree:- number of nodes in the longest path between any 2 leaves
*/
int diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=heightofbt(root->left);
    int rheight=heightofbt(root->right);
    int currdia=lheight+rheight;
    int ldia=diameter(root->left);
    int rdia=diameter(root->right);
    return max(currdia,max(ldia,rdia));
}
int caldiameter(Node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldia=caldiameter(root->left,&lh);
    int rdia=caldiameter(root->right,&rh);
    int currdia=lh+rh;
    *height=max(lh,rh)+1;
    return max(currdia,max(ldia,rdia));
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right= new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    int height=0;
    cout<<caldiameter(root,&height)<<" ";
}
/*Given a Binary Tree, you need to find the maximum 
value which you can get by subtracting the value of
node B from the value of node A, where A and B are
two nodes of the binary tree and A is an ancestor of B. */
void solve(Node*root, int curr, int &ans){
    if(!root)return;
    ans=max(ans,curr-root->data);
    curr=max(curr, root->data);
    solve(root->left, curr, ans);
    solve(root->right, curr, ans);

}
int maxdiff(Node*root){
    int ans=INT_MIN;
    solve(root, ans+root->data,ans);
    return ans;

}
/*2*/
int solve(Node*root, int &maxdiff){
    if(!root)return INT_MAX;
    if(!root->left && !root->right)return root->data;
    int left=solve(root->left, maxdiff);
    int right=solve(root->right, maxdiff);
    maxdiff=max(maxdiff, root->data-min(left,right));
    return min(min(left,right),root->data);
}
int maxdiff(Node*root){
    int maxdiff=INT_MIN;
    
}
