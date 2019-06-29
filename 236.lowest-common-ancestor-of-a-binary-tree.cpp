/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path;
        vector<TreeNode *> node_p_path;
        vector<TreeNode *> node_q_path;
        bool finish = false;
        preOrder(root, p, path, node_p_path, finish);
        path.clear();
        finish = false;
        preOrder(root, q, path, node_q_path, finish);
        int path_len = 0;
        if (node_p_path.size() < node_q_path.size())
            path_len = node_p_path.size();
        else
        {
            path_len = node_q_path.size();
        }
        TreeNode *res = nullptr;
        for (int i = 0; i < path_len; i++)
        {
            if (node_p_path[i] == node_q_path[i])
            {
                res = node_p_path[i];
            }
        }
        return res;
    }

private:
    void preOrder(TreeNode *node, TreeNode *search, vector<TreeNode *> &path, vector<TreeNode *> &result, bool &finish)
    {
        if (node == nullptr || finish)
            return;
        path.push_back(node);
        if (node == search)
        {
            finish = true;
            result = path;
        }
        preOrder(node->left, search, path, result, finish);
        preOrder(node->right, search, path, result, finish);
        path.pop_back();
    }
};
