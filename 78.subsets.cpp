/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int all_set = 1 << nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < all_set; i++)
        {
            vector<int> item;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j))
                    item.push_back(nums[j]);
            }
            res.push_back(item);
        }
        return res;
    }
};

/* 
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> item;
        res.push_back(item);
        generate(0, nums, item, res);
        return res;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &res)
    {
        if (i >= nums.size())
            return;
        item.push_back(nums[i]);
        res.push_back(item);
        generate(i + 1, nums, item, res);
        item.pop_back();
        generate(i + 1, nums, item, res);
    }
};*/
