/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() == 0)
            return 0;
        int i = 0, j = 0;
        int len = nums.size();
        int temp = 0;

        while (j < len)
        {
            if (nums[i] != nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            if (i <= j || nums[j] == val)
                j++;
            if (nums[i] != val)
                i++;
        }
        return i;
    }
};
