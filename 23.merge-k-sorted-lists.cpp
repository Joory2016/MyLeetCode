/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool myComp(ListNode *l1, ListNode *l2)
{
    return l1->val <= l2->val;
}

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> node_vec;
        int numLists = lists.size();
        for (int i = 0; i < numLists; i++)
        {
            ListNode *temp_head = lists[i];
            while (temp_head != nullptr)
            {
                node_vec.push_back(temp_head);
                temp_head = temp_head->next;
            }
        }
        if (node_vec.size() == 0)
            return nullptr;
        sort(node_vec.begin(), node_vec.end(), myComp);
        node_vec.push_back(nullptr);
        int len = node_vec.size();
        for (int i = 0; i < len - 1; i++)
            node_vec[i]->next = node_vec[i + 1];
        return node_vec[0];
    }
};
