// Q] Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

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
            len += 1;
            curr = curr->next;
        }

        return len;
    }
    ListNode* middleNode(ListNode* head) {
        // int len = lenOfList(head);
        // int middle = len/2;

        // while(middle > 0){
        //     head = head->next;
        //     middle--;
        // }
        ListNode *slow, *fast;
        slow = fast = head;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;

            if(fast->next != NULL) fast = fast->next;
        }

        return slow;
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

    obj.middleNode(head);
    return 0;
}