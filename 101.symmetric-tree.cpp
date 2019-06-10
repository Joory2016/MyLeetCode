/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetric(root, root);
    }

private:
    bool isSymmetric(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        if (r1 == nullptr || r2 == nullptr)
            return false;
        if (r1->val != r2->val)
            return false;
        return isSymmetric(r1->left, r2->right) &&
               isSymmetric(r1->right, r2->left);
    }
};
