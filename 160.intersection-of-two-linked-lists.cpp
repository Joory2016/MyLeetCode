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
/*
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
 */

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = countLen(headA);
        int lenB = countLen(headB);
        ListNode *longList = nullptr;
        ListNode *shortList = nullptr;
        int diff = 0;
        if (lenA >= lenB)
        {
            diff = lenA - lenB;
            longList = headA;
            shortList = headB;
        }
        else
        {
            diff = lenB - lenA;
            longList = headB;
            shortList = headA;
        }
        for (int i = 0; i < diff; i++)
            longList = longList->next;
        while (longList != shortList)
        {
            if (longList == nullptr)
                return nullptr;
            longList = longList->next;
            shortList = shortList->next;
        }
        return longList;
    }

private:
    int countLen(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};
