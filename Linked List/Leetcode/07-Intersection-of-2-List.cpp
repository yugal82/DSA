// Q] Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;

        while(curr1 != curr2){
            if(curr1 == nullptr) curr1 = headB;
            else curr1 = curr1->next;

            if(curr2 == nullptr) curr2 = headA;
            else curr2 = curr2->next;
        }

        return curr1;
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

    obj.getIntersectionNode(head1, head2);
    return 0;
}