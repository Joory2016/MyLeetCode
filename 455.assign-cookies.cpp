/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0; //child
        int j = 0; //cookies
        int res = 0;
        while (j < s.size() && i < g.size())
        {
            if (g[i] <= s[j])
            {
                i++;
                j++;
                res++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};
