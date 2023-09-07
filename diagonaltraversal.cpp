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
void mapfill(Node*root, int d, map<int,vector<int>>&m){
    if(!root){
        return ;
    }
    m[d].push_back(root->data);
    mapfill(root->left,d+1,m);
    mapfill(root->right,d,m);
}
vector<int> diagonalPrint(Node*root){
    vector<int>ans;
    map<int,vector<int>> m;
    mapfill(root,0,m);
    for(auto it: m){
        vector<int> v=it.second;
        for(auto it:v){
            ans.push_back(it);
        }
    }
    return ans;
}
