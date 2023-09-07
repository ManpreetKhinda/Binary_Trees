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
bool getpath(Node*root, vector<int>&arr, int x){
    if(!root)return 0;
    arr.push_back(root->data);
    if(root->data==x)return true;
    if(getpath(root->left,arr,x)|| getpath(root->right,arr,x))return true;
    arr.pop_back();
    return false;
}
vector<int> path(Node*root, int a){
    if(root==NULL)return {};
    vector<int>arr;
    getpath(root,arr,a);
    return arr;
}