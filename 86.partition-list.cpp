/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode lessHead(0);
        ListNode moreHead(0);
        ListNode *less_ptr = &lessHead;
        ListNode *more_ptr = &moreHead;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                less_ptr->next = head;
                less_ptr = less_ptr->next;
            }
            else
            {
                more_ptr->next = head;
                more_ptr = more_ptr->next;
            }
            head = head->next;
        }
        less_ptr->next = moreHead.next;
        more_ptr->next = nullptr;
        return lessHead.next;
    }
};
