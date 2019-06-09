/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (54.86%)
 * Likes:    2339
 * Dislikes: 63
 * Total Accepted:    595.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *res = nullptr;
        ListNode *pNode = head;
        ListNode *pPre = nullptr;
        while (pNode != nullptr)
        {
            ListNode *pNext = pNode->next;
            if (pNext == nullptr) //key
                res = pNode;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return res;
    }
};
