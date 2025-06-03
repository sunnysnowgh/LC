// leetcode 24
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    ListNode* back2NoHeadNodeList(ListNode* headNode) {
            ListNode* newHead = headNode->next;
            delete headNode;
            return newHead;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* emptyHead = new ListNode(0, head);

        ListNode* pre = emptyHead;
        ListNode* oddNode = nullptr;
        ListNode* evenNode = nullptr;
        while (true) {
            oddNode = pre->next;
            if(!oddNode) {
                return back2NoHeadNodeList(emptyHead);
            }
            evenNode = oddNode->next;
            if (!evenNode) {
                return back2NoHeadNodeList(emptyHead);
            }
            oddNode->next = evenNode->next;
            evenNode->next = oddNode;
            pre->next = evenNode;
            pre = oddNode;
        }
    }
};