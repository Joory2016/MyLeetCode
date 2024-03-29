/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        vector<int> path;
        int path_value = 0;
        preOrder(root, path_value, sum, path, res);
        return res;
    }

private:
    void preOrder(TreeNode *node, int &path_value, int sum, vector<int> &path, vector<vector<int>> &res)
    {
        if (node == nullptr)
            return;
        path_value += node->val;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
            if (path_value == sum)
                res.push_back(path);
        preOrder(node->left, path_value, sum, path, res);
        preOrder(node->right, path_value, sum, path, res);
        path_value -= node->val;
        path.pop_back();
    }
};
