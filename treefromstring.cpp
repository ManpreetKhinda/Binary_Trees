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
Node*constructtree(string&s, int* start){
    if(s.size()==0 || *start>=s.size()){
        return NULL;
    }
    int num=0;
    while(*start<s.size() && s[*start]!='(' && s[*start]!=')'){
        int num_here=(int)(s[*start]-'0');
        num=num*10+num_here;
        *start++;
    }
    struct Node*root=NULL;
    if(num>0){
        root=new Node(num);
    }
    if(*start<s.size() && s[*start]=='('){
        *start++;
        root->left=constructtree(s,start);
    }
    if(*start<s.size() && s[*start]==')'){
        *start++;
        return root;
    }
    if(*start<s.size() && s[*start]=='('){
        *start++;
        root->right=constructtree(s,start);
    }
    if(*start<s.size() && s[*start]==')'){
        *start++;
    }
    return root;
}