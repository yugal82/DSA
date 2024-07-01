// Q] You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr){
            ListNode *node = new ListNode();
            int add = carry;
            if(l1 != nullptr){
                add += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                add += l2->val;
                l2 = l2->next;
            }

            node->val = (add % 10);
            curr->next = node;
            curr = node;

            if(add > 9) carry = 1;
            else carry = 0;
        }

        if(carry == 1){
            ListNode *node = new ListNode(carry);
            curr->next = node;
            curr = node;
        }

        return dummy->next;
    }
};

int main(){
    Solution obj;
    int n = 4;
    ListNode *head1 = new ListNode(1);
    ListNode *curr1 = head1;

    ListNode *head2 = new ListNode(1);
    ListNode *curr2 = head2;

    while(n > 0){
        ListNode *first = new ListNode(n);
        curr1->next = first;
        curr1 = first;

        ListNode *second = new ListNode(n);
        curr2->next = second;
        curr2 = second;
    }

    obj.addTwoNumbers(head1, head2);
    return 0;
}