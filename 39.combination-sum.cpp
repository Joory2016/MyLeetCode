/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        compute(0, target, temp, candidates, res);
        return res;
    }

private:
    void compute(int start, int target, vector<int> &temp, vector<int> &candidates, vector<vector<int>> &res)
    {
        int n = candidates.size();
        for (int i = start; i < n; i++)
        {
            if (target > 0)
            {
                temp.push_back(candidates[i]);
                compute(i, target - candidates[i], temp, candidates, res);
                temp.pop_back();
            }
            else if (target < 0)
                return;
            else
            {
                res.push_back(temp);
                return;
            }
        }
    }
};
