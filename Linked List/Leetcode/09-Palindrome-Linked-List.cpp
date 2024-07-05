// Q] Given the head of a singly linked list, return true if it is a palindrome or false otherwise

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
        follow = NULL;
        while(curr != NULL){
            ahead = curr->next;
            curr->next = follow;
            follow = curr;
            curr = ahead;
        }
        return follow;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;

            if(fast->next != NULL) fast = fast->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *middle = middleNode(head);
        ListNode *reversedNode = reverseList(middle);
        while(reversedNode != nullptr){
            if(head->val != reversedNode->val) return false;

            head = head->next;
            reversedNode = reversedNode->next;
        }
        return true;
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

    obj.isPalindrome(head);
    return 0;
}