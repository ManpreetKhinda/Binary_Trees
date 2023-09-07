#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> traversal;
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
/*check whether a tree is mirrored about centre*/
bool check(Node*left,Node*right){
    if(!left||!right)return left==right;
    if(left->data!=right->data)return false;
    return check(left->left, right->right)&&check(left->right,right->left);
}
bool isSymmetric(Node*root){
    return root==NULL||check(root->left,root->right);
}
