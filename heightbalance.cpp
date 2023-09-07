/*
balanced height tree
for each node the difference between 
the heights fo the left subtree
and right subtree<=1
*/
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
int heightofbt(Node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=heightofbt(root->left);
    int rheight=heightofbt(root->right);
    return max(lheight,rheight)+1;
}
bool isbalanced(Node *root){
    if(root==NULL){
        return true;
    }
    if(isbalanced(root->left)==false){
        return false;
    }
    if(isbalanced(root->right)==false){
        return false;
    }
    int lh=heightofbt(root->left);
    int rh=heightofbt(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
bool isbalanced(Node*root, int*height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(isbalanced(root->left,&lh)==false){
        return false;
    }
    if(isbalanced(root->right,&rh)==false){
        return false;
    }
    *height=max(rh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
