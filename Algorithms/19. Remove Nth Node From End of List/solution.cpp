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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
        {
            return head;
        }

        int size = 0;
        ListNode *temp = head;

        while (temp)
        {
            size++;
            temp = temp->next;
        }

        if (n == size)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;
        for (int i = 1; i < size - n; i++)
        {
            temp = temp->next;
        }

        ListNode *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};