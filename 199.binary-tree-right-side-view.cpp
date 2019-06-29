/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
//find the last node in every layer
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> view;
        queue<pair<TreeNode *, int>> Q;

        if (root)
        {
            Q.push(make_pair(root, 0));
        }
        while (!Q.empty())
        {
            TreeNode *node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if (view.size() == depth)
            {
                view.push_back(node->val);
            }
            else
            {
                view[depth] = node->val;
            }
            if (node->left)
                Q.push(make_pair(node->left, depth + 1));
            if (node->right)
                Q.push(make_pair(node->right, depth + 1));
        }
        return view;
    }
};
