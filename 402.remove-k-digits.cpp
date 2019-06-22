/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> s;
        string res = "";
        for (int i = 0; i < num.length(); i++)
        {
            int number = num[i] - '0';
            while (s.size() != 0 && s.back() > number && k > 0)
            {
                s.pop_back();
                k--;
            }
            if (number != 0 || s.size() != 0)
            {
                s.push_back(number);
            }
        }
        while (s.size() != 0 && k > 0)
        {
            s.pop_back();
            k--;
        }
        for (int i = 0; i < s.size(); i++)
        {
            res.append(1, '0' + s[i]);
        }
        if (res == "")
            res = "0";
        return res;
    }
};
