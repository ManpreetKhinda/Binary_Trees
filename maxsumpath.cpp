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
/*
for each node compute
node val 
max path through left child+ node val
max path through right child +node val
max path through left child + max path through right child +node val
*/
int maxpathsumutil(Node*root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=maxpathsumutil(root->left,ans);
    int right=maxpathsumutil(root->right,ans);
    int nodemax=max(max(root->data,root->data+right+left),
                    max(root->data+left,root->data+right));
    ans=max(ans,nodemax);

    int singlepathsum=max(root->data,max(root->data+left,root->data+right));
    return singlepathsum;
}
int maxpathsum(Node*root){
    int ans=INT_MIN;

    maxpathsumutil(root,ans);
    return ans;
}

int maxpath(Node*root, int &maxi){
    if(!root)return 0;
    int left=max(0,maxpath(root->left,maxi));
    int right=max(0, maxpath(root->left,maxi));
    maxi=max(maxi,left+right+root->data);
    return max(left,right)+root->data;
}
int maxpathsums(Node*root){
    int maxi=INT_MIN;
    maxpath(root, maxi);
    return maxi;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left= new Node(6);
    root->right->left= new Node(3);
    root->right->right= new Node(4);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->left->left->right->right = new Node(9);
    cout<<maxpathsum(root);
    return 0;
}