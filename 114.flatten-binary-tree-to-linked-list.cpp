/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *last = nullptr;
        preOrder(root, last);
    }

private:
    void preOrder(TreeNode *node, TreeNode *&last)
    {
        if (!node)
            return;
        if (!node->left && !node->right)
        {
            last = node;
            return;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *left_last = nullptr;
        TreeNode *right_last = nullptr;
        if (left)
        {
            preOrder(left, left_last);
            node->left = nullptr;
            node->right = left;
            last = left_last;
        }
        if (right)
        {
            preOrder(right, right_last);
            if (left_last)
            {
                left_last->right = right;
            }
            last = right_last;
        }
    }
};

/* 
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> v;
        preOrder(root, v);
        v.push_back(nullptr);
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i]->right = v[i + 1];
            v[i]->left = nullptr;
        }
    }

    void preOrder(TreeNode *node, vector<TreeNode *> &v)
    {
        if (node == nullptr)
            return;
        v.push_back(node);
        preOrder(node->left, v);
        preOrder(node->right, v);
    }
};
*/
