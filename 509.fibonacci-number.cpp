/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        if (N == 2)
            return 1;
        int res = 0;
        int first = 1;
        int second = 1;
        while (N > 2)
        {
            res = first + second;
            first = second;
            second = res;
            N--;
        }
        return res;
    }
};
