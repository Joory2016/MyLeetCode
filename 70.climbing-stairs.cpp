/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
class Solution
{ //fibonacci
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int first = 1;
        int second = 1;
        int res = 0;
        while (n > 1)
        {
            res = first + second;
            first = second;
            second = res;
            n--;
        }
        return res;
    }
};
