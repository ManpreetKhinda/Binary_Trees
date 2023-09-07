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
bool precheck(Node*root,int level, int *leaflevel){
    if(root==NULL){
        return true;
    }
    if((!root->left)&&(!root->right)){
        if(*leaflevel==0){
            *leaflevel=level;
            return true;
        }
        else{
            return (level==*leaflevel);
        }
    }
    return precheck(root->left,level+1,leaflevel) && precheck(root->right,level+1,leaflevel);
}
bool check(Node*root){
    int level=0,leaflevel=0;
    return precheck(root,level,&leaflevel);
}