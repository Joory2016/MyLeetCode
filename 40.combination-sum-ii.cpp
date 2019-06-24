/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> res_set;
        sort(candidates.begin(), candidates.end());
        compute(0, target, temp, candidates, res, res_set);
        return res;
    }

private:
    void compute(int start, int target, vector<int> &temp, vector<int> &candidates, vector<vector<int>> &res, set<vector<int>> &res_set)
    {
        int n = candidates.size();
        for (int i = start; i < n; i++)
        {
            if (target > 0)
            {
                temp.push_back(candidates[i]);
                compute(i + 1, target - candidates[i], temp, candidates, res, res_set);
                temp.pop_back();
            }
            else if (target < 0)
                return;
            else if (res_set.find(temp) == res_set.end())
            {
                res.push_back(temp);
                res_set.insert(temp);
                return;
            }
        }
    }
};
