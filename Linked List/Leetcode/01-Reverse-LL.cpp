// Q] Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr, *follow, *ahead;
        curr = head;
        follow = nullptr;

        while(curr != nullptr){
            ahead = curr->next;
            curr->next = follow;
            follow = curr;
            curr = ahead;
        }

        return follow;
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

    obj.reverseList(head);
    return 0;
}