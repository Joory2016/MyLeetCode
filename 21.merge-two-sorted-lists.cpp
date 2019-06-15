/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 != nullptr && l2 == nullptr)
            return l1;
        if (l2 != nullptr && l1 == nullptr)
            return l2;
        ListNode *res = nullptr;
        if (l1->val <= l2->val)
        {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        return res;
    }
};

*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode temp_head(0);
        ListNode *pre = &temp_head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if (l1 != nullptr)
            pre->next = l1;
        if (l2 != nullptr)
            pre->next = l2;
        return temp_head.next;
    }
};
