/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
/* 
class Solution
{
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        int sum = 0;
        set<int> s_sum;
        while (sum != 1)
        {
            s_sum.insert(n);
            sum = countN(n);
            if (sum == 1)
                return true;
            if (s_sum.count(sum))
                return false;
            n = sum;
        }
        return true;
    }

private:
    int countN(int n)
    {
        int res = 0;
        while (n)
        {
            int temp = n % 10;
            res = res + temp * temp;
            n = n / 10;
        }
        return res;
    }
};
*/
class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        int slow = n, fast = n;
        do
        {
            slow = countN(slow);
            fast = countN(fast);
            fast = countN(fast);
            if (fast == 1)
                return true;
        } while (fast != slow);
        return false;
    }

private:
    int countN(int n)
    {
        int res = 0;
        while (n != 0)
        {
            int temp = n % 10;
            res = res + temp * temp;
            n = n / 10;
        }
        return res;
    }
};
