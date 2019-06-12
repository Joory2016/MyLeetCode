/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> node_set;
        while (headA != nullptr)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr)
        {
            if (node_set.count(headB))
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
