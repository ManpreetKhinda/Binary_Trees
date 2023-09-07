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
bool getpath(Node*root, int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getpath(root->left,key,path)||getpath(root->right,key,path)){
        return true;

    }
    path.pop_back();
    return false;

}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
    if(!getpath(root, n1,path1)||!getpath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size()&&path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}
//single path traversal
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
    Node* lca=lca2(root,5,9);
    cout<<lca->data<<endl;
}