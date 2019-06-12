/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int len = n - m + 1;
        ListNode *pre_head = nullptr;
        ListNode *res = head;
        while (head != nullptr && --m)
        {
            pre_head = head;
            head = head->next;
        }
        ListNode *modify_list_tail = head;
        ListNode *new_head = nullptr;
        while (head != nullptr && len)
        {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            len--;
        }
        modify_list_tail->next = head;
        if (pre_head != nullptr)
            pre_head->next = new_head;
        else
        {
            res = new_head;
        }
        return res;
    }
};
