/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *p = head;
        while (p->next != nullptr)
        {
            if (p->next->val == val)
            {
                ListNode *temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
            {
                p = p->next;
            }
        }
        if (head->val == val)
            head = head->next;
        return head;
    }
};
