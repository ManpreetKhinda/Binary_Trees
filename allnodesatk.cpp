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
void printsubtreenode(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printsubtreenode(root->left, k - 1);
    printsubtreenode(root->right, k - 1);
}
int nodesatk(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printsubtreenode(root, k);
        return 0;
    }
    int dl = nodesatk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtreenode(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = nodesatk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtreenode(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}
void markparents(Node *root, unordered_map<Node *, Node *> &parent_track, Node *target)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left)
        {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector<int> atdistanceK(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> parent_track;
    markparents(root, parent_track, target);
    unordered_map<Node *, bool> vis;
    queue<Node *> q;
    vis[target] = 1;
    int currlevel = 0;
    while (!q.empty())
    {
        int n = q.size();
        if (currlevel++ == k)
            break;
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left && !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left] = 1;
            }
            if (curr->right && !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right] = 1;
            }
            if (parent_track[curr] && !vis[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                vis[parent_track[curr]] = 1;
            }
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        result.push_back(curr->data);
    }
    return result;
}
/* nodes at k distance form leaves*/
void f(Node *root, vector<Node *> &v, int k, unordered_set<Node *> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        if (v.size() >= k)
        {
            ans.insert(v[v.size() - k]);
        }
        return;
    }
    v.push_back(root);
    f(root->left, v, k, ans);
    f(root->right, v, k, ans);
    v.pop_back();
    return;
}
int printkdistanceformleaf(Node *root, int k)
{
    vector<Node *> v;
    unordered_set<Node *> ans;
    f(root, v, k, ans);
    return ans.size();
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->left->left->right->right = new Node(9);

    nodesatk(root, root->left, 3);
    return 0;
}