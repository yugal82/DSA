// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    int lenOfList(ListNode *head){
        ListNode *curr = head;
        int len = 0;
        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lenOfList(head);
        int nthNode = len - n;

        ListNode *curr, *follow;
        curr = head;
        follow = NULL;
        while(nthNode > 0){
            follow = curr;
            curr = follow->next;
            nthNode--;
        }

        if(follow == NULL) return head->next;

        follow->next = curr->next;
        curr->next = NULL;
        
        return head;
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

    obj.removeNthFromEnd(head, 3);
    return 0;
}