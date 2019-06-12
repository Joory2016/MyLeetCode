/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
class Solution
{
public:
    /* 
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        map<int, int> map_h;
        int sum = 0;
        while (sum != 1)
        {
            map_h.insert(pair<int, int>(n, n));
            sum = countN(n);
            if (sum == 1)
                return true;
            if (map_h.count(sum))
                return false;
            n = sum;
        }
        return true;
    }
*/

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
