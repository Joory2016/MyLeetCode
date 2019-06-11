/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
/* 
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

class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (isPrime(i))
            {
                ++count;
                primes.push_back(i);
            }
        }
        return count;
    }

private:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        int sq = sqrt(n);
        int len = primes.size();
        for (int index = 0; index < len; index++)
        {
            int temp = primes[index];
            if (temp > sq)
                break;
            if (n % temp == 0)
                return false;
        }
        return true;
    }

    vector<int> primes;
};
*/

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        bool *isPrime = new bool[n];
        for (int i = 2; i < n; i++)
            isPrime[i] = true;

        for (int i = 2; i * i < n; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
                count++;
        }
        delete[] isPrime;
        return count;
    }
};
