// QUESTION:
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

bool solve(TreeNode *p, TreeNode *q){
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    bool left = solve(p->left, q->left);
    bool right = solve(p->right, q->right);

    if ((p->val == q->val) && left && right)
        return true;
    else
        return false;
}

bool isSameTree(TreeNode *p, TreeNode *q){
    return solve(p, q);
}

int main(){
    // make two objects of TreeNode struct and create two trees out of it and call isSameTree to check if they both are structurally as well as value wise same.
    return 0;
}