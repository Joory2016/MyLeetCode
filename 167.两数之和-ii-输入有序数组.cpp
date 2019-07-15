/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 * using two pointers
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int head = 1;
        int tail = numbers.size();
        vector<int> res(2, -1);
        while (head < tail)
        {
            if ((numbers[head - 1] + numbers[tail - 1]) == target)
            {
                res[0] = head;
                res[1] = tail;
                break;
            }
            else if ((numbers[head - 1] + numbers[tail - 1]) < target)
                ++head;
            else if ((numbers[head - 1] + numbers[tail - 1]) > target)
                --tail;
        }
        return res;
    }
};
