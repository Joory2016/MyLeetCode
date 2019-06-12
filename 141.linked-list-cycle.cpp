/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        do
        {
            if (slow->next == nullptr)
                return false;
            slow = slow->next;
            if (fast->next == nullptr || fast->next->next == nullptr)
                return false;
            fast = fast->next->next;
        } while (fast != slow);
        return true;
    }
};
