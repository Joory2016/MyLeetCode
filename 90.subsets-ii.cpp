/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        res.push_back(item);
        generate(0, nums, res, item, res_set);
        return res;
    }

private:
    void generate(int i, vector<int> &nums, vector<vector<int>> &res, vector<int> &item, set<vector<int>> &res_set)
    {
        if (i >= nums.size())
            return;
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end())
        {
            res_set.insert(item);
            res.push_back(item);
        }
        generate(i + 1, nums, res, item, res_set);
        item.pop_back();
        generate(i + 1, nums, res, item, res_set);
    }
};
