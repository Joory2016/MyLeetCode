/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
class Solution
{
    int nums = 0;
    //   vector<vector<string>> vvs;

public:
    int totalNQueens(int n)
    {
        vector<int> vi(n);
        solve(vi, n, 0);
        //        return vvs.size();
        return nums;
    }

private:
    void solve(vector<int> &vi, int n, int c)
    {
        if (c == n)
        {
            //            vector<string> vs(n, string(n, '.'));
            //            for (int i = 0; i < n; ++i)
            //                vs[i][vi[i]] = 'Q';
            //            vvs.push_back(vs);
            nums++;
            return;
        }
        for (vi[c] = 0; vi[c] < n; ++vi[c])
        {
            if (safe(vi, n, c))
                solve(vi, n, c + 1);
        }
    }

    bool safe(vector<int> &vi, int n, int c)
    {
        for (int i = 0; i < c; ++i)
        {
            if (vi[i] == vi[c] || abs(vi[c] - vi[i]) == abs(c - i))
                return false;
        }
        return true;
    }
};
