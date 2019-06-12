/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *pNodeInCycle = findNodeInCycle(head);
        if (pNodeInCycle == nullptr)
            return nullptr;
        int numNodeCycle = 1;
        ListNode *temp = pNodeInCycle->next;
        while (temp != pNodeInCycle)
        {
            numNodeCycle++;
            temp = temp->next;
        }
        temp = head;
        ListNode *res = head;
        for (int i = 0; i < numNodeCycle; i++)
            temp = temp->next;
        while (res != temp)
        {
            temp = temp->next;
            res = res->next;
        }
        return res;
    }

private:
    ListNode *findNodeInCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        do
        {
            if (slow->next == nullptr)
                return nullptr;
            slow = slow->next;
            if (fast->next == nullptr || fast->next->next == nullptr)
                return nullptr;
            fast = fast->next->next;
        } while (fast != slow);
        return fast;
    }
};
