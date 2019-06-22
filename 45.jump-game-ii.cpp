/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int current_max_index = nums[0]; //当前可达到的最远位置
        int pre_max_max_index = nums[0]; //遍历各个位置中，可达到的最远位置
        int jump_min = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > current_max_index) //如果无法再向前移动，才进行跳跃
            {
                jump_min++; //即更新当前可达到的最远位置
                current_max_index = pre_max_max_index;
            }
            if (pre_max_max_index < nums[i] + i)
            {
                pre_max_max_index = nums[i] + i;
            }
        }
        return jump_min;
    }
};
