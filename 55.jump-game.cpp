/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> index; //store the farthest position
        for (int i = 0; i < nums.size(); i++)
            index.push_back(i + nums[i]);
        int jump = 0;
        int max_index = index[0];
        while (jump < index.size() && jump <= max_index)
        {
            if (index[jump] >= max_index)
            {
                max_index = index[jump];
            }
            jump++;
        }
        if (jump == index.size())
            return true;
        return false;
    }
};
