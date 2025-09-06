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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1 != nullptr)
        {
            current->next = l1;
        }
        if (l2 != nullptr)
        {
            current->next = l2;
        }

        ListNode *mergedList = dummy->next;
        delete dummy;
        return mergedList;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (!lists.size())
        {
            return nullptr;
        }

        while (lists.size() > 1)
        {
            vector<ListNode *> merged;
            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                merged.push_back(mergeTwoLists(l1, l2));
            }
            lists = merged;
        }

        return lists[0];
    }
};