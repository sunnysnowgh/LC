// leetcode 21
// 合并两个有序链表
//Definition for singly-linked list.
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
        ListNode *res = new ListNode();
        ListNode *end = res;
        while (true) {
            if(list1 == nullptr) {
                end->next = list2;
                break;
            }
            if(list2 == nullptr) {
                end->next = list1;
                break;
            }
            if(list1->val < list2->val) {
                end->next = list1;
                end = list1;
                list1 = list1->next;
            } else {
                end->next = list2;
                end = list2;
                list2 = list2->next;
            }
        }
        ListNode* mid = res;
        res = res->next;
        delete mid;
        return res;
    }
};