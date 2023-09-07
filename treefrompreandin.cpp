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

/*
pick elements from preorder and create a node
increment preorder idx
search for picked elements pos in inorder
call to build left subtree from inorder's 0 to pos-1
call to build right subtree from inorder pos+1 to n
return the node
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 

*/
int search(int inorder[], int  start, int end, int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }return -1;
}
Node*buildtree(int preorder[],int inorder[], int start, int end){

    static int idx=0;
    if(start>end){
        return NULL;
    }

    int curr=preorder[idx];
    idx++;
    Node*node= new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder, start, end, curr);
    node->left=buildtree(preorder,inorder,start, pos-1);
    node->right=buildtree(preorder,inorder,pos+1,end);
    return node;
    

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
    int preordr[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    Node*root=buildtree(preordr,inorder,0,6);
    inorderprint(root);
}