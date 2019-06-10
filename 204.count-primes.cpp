/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
class Solution
{
public:
    int countPrimes(int n)
    {
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (isPrime(i))
                res++;
        }
        return res;
    }

private:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        int temp = sqrt(n);
        for (int i = 2; i <= temp; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};