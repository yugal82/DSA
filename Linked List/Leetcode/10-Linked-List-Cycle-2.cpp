// Q] Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter. Do not modify the linked list

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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || (head->next == nullptr && head->next != head)) return nullptr;
        ListNode *slow = head, *fast = head;

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr) fast = fast->next;

            if(slow == fast) break;
        }

        if(fast == nullptr) return nullptr;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
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

    obj.detectCycle(head);
    return 0;
}