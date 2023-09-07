/*
start from the end of postorder &pick an element to create a node
decrement postorder idx
search for picked element's pos in inorder
call to build right subtree from inorder's pos+1 to n
call to build left subtree from inorder 0 to pos-1
return the node
4 5 2 6 7 3 1 
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
int search(int inorder[],int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
Node*buildtree(int postorder[],int inorder[],int start, int end){
    static int idx=6;
    if(start>end){
        return NULL;
    }
    int val=postorder[idx];
    idx--;
    // Node curr=new node(val);
    Node *curr= new Node(val);
    if(start==end){
        return curr;
    }
    int pos= search(inorder, start, end,val);
    curr->right=buildtree(postorder, inorder, pos+1, end);
    curr->left=buildtree(postorder,inorder,start,pos-1);
    return curr;
}
void inorderprint(Node*root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);   
}
int main(){
    int postorder[]={4,5,2,6,7,3,1};
    int inorder[]={4,2,5,1,6,3,7};
    Node*root=buildtree(postorder,inorder,0,6);
    inorderprint(root);
    return 0;
}