// There is a singly-linked list head and we want to delete a node node in it. You are given the node to be deleted node. You will not be given access to the first node of head.
// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list. Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean: The value of the given node should not exist in the linked list. The number of nodes in the linked list should decrease by one. All the values before node should be in the same order. All the values after node should be in the same order.

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};

int main(){
    Solution obj;
    ListNode *head = new ListNode(1);
    int n = 4;
    ListNode *curr = head;
    while(n > 0){
        ListNode *node = new ListNode(n);
        curr->next = node;
        curr = node;
    }

    // here we cannot only pass the node that we want to delete as we dont have the system build as same as leetcode😅. So we pass the head node only.
    obj.deleteNode(head);
    return 0;
}