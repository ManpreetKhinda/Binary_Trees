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
Node* lca2(Node*root, int n2, int n1){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root;
    }
    Node*leftlca=lca2(root->left,n2,n1);
    Node*rightlca=lca2(root->right,n2,n1);

    if(leftlca && rightlca){
        return root;
    }
    if(leftlca!=NULL){
        return leftlca;
    }
    return rightlca;
}
int finddist(Node*root, int k,int dist){
    if(root==NULL){
        return-1;
    }
    if(root->data==k){
        return dist;
    }
    int left=finddist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return finddist(root->right,k,dist+1);
}
int nodedistance(Node*root, int n1, int n2){
    Node*lca=lca2(root,n1,n2);
    int d1=finddist(lca,n1,0);
    int d2=finddist(lca,n2,0);
    return d1+d2;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right= new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<nodedistance(root,5,7);
    return 0;
}