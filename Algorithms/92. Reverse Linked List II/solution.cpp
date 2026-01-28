/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* leftPrev = &dummy;
        ListNode* curr = head;

        for (int i = 1; i < left; i++) {
            leftPrev = curr;
            curr = curr->next;
        }

        ListNode* prev = NULL;
        ListNode* start = curr;

        for (int i = 0; i <= right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        leftPrev->next = prev;
        start->next = curr;

        return dummy.next;
    }
};