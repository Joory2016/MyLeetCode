/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    /* 
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool res = false;
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        if (p->val == q->val)
            res = (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        return res;
    }
    */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool res = true;
        if (p == nullptr && q == nullptr)
            return true;
        stack<TreeNode *> sp;
        stack<TreeNode *> sq;
        sp.push(p);
        sq.push(q);
        while (!sp.empty())
        {
            TreeNode *ptemp = sp.top();
            TreeNode *qtemp = sq.top();
            if (check(ptemp, qtemp))
                res = true;
            else
            {
                res = false;
                break;
            }
            sp.pop();
            sq.pop();
            if (ptemp->left != nullptr && qtemp->left != nullptr)
            {
                sp.push(ptemp->left);
                sq.push(qtemp->left);
            }
            else if (ptemp->left != nullptr || qtemp->left != nullptr)
            {
                return false;
            }

            if (ptemp->right != nullptr && qtemp->right != nullptr)
            {
                sp.push(ptemp->right);
                sq.push(qtemp->right);
            }
            else if (ptemp->right != nullptr || qtemp->right != nullptr)
            {
                return false;
            }
        }
        return res;
    }

private:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return true;
    }
};
