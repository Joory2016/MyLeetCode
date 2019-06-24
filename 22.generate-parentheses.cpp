/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generate("", n, n, res);
        return res;
    }

private:
    void generate(string item, int left, int right, vector<string> &res)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(item);
        }
        if (left > 0)
        {
            generate(item + "(", left - 1, right, res);
        }
        if (left < right)
        {
            generate(item + ")", left, right - 1, res);
        }
    }
};
