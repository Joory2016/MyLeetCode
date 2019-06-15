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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int numLists = lists.size();
        if (numLists == 0)
            return nullptr;
        if (numLists == 1)
            return lists[0];
        if (numLists == 2)
            return mergeTwoLists(lists[0], lists[1]);
        int mid = numLists / 2;
        vector<ListNode *> sub1_lists;
        vector<ListNode *> sub2_lists;
        for (int i = 0; i < mid; i++)
            sub1_lists.push_back(lists[i]);
        for (int i = mid; i < numLists; i++)
            sub2_lists.push_back(lists[i]);
        ListNode *l1 = mergeKLists(sub1_lists); //divide and conquer
        ListNode *l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1, l2);
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode pre_head(0);
        ListNode *pre = &pre_head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
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
        return pre_head.next;
    }
};

/*
bool myComp(ListNode *l1, ListNode *l2)
{
    return l1->val < l2->val;
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

 */
