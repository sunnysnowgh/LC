// leetcode 19
// 删除链表后的倒数第N个结点
// Definition for singly-linked list.
#include<cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* leader = head;
        ListNode* toDelete = head;
        ListNode* priToDelete = nullptr;
        for (size_t i = 0; i < n; i++) {
            leader = leader->next;
        }
        if (leader == nullptr) return head->next;
        do {
            leader = leader->next;
            priToDelete = toDelete;
            toDelete = toDelete->next;
        } while (leader != nullptr);
        priToDelete->next = toDelete->next;
        return head;
    }
};