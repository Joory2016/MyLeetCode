/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        return check(root, sum);
    }

private:
    bool check(TreeNode *node, int sum)
    {
        if (node == nullptr)
            return false;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum == node->val)
                return true;
        }

        if (check(node->left, sum - (node->val)))
            return true;
        if (check(node->right, sum - (node->val)))
            return true;
        return false;
    }
};
