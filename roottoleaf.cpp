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
void traverse(Node*root, vector<int>&temp, vector<vector<int>>& paths){
    if(!root)return;
    temp.push_back(root->data);
    traverse(root->left, temp,paths);
    traverse(root->right,temp,paths);
    if(!root->left && !root->right)paths.push_back(temp);
    temp.pop_back();
}