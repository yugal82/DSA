// You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;

        if(list2 == nullptr)
            return list1;

        ListNode *i = list1, *j = list2;
        ListNode *head = new ListNode();
        ListNode *curr = head;
        while(i != nullptr && j != nullptr){
            ListNode *node = new ListNode();

            if(i->val < j->val){
                node->val = i->val;
                i = i->next;
            }
            else{
                node->val = j->val;
                j = j->next;
            }

            curr->next = node;
            curr = node;
        }

        while(i != nullptr){
            ListNode *node = new ListNode();
            node->val = i->val;
            i = i->next;
            curr->next = node;
            curr = node;
        }

        while(j != nullptr){
            ListNode *node = new ListNode();
            node->val = j->val;
            j = j->next;
            curr->next = node;
            curr = node;
        }

        return head->next;
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

    obj.mergeTwoLists(head1, head2);
    return 0;
}