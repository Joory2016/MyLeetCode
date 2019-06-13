/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 * 
 * find the same string in two list, and find minimum of the sum of 
 * two indexes of strings in lists, and return the string.
 * 
 */
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int len1 = list1.size();
        int len2 = list2.size();
        vector<string> res;
        map<string, int> s_map;
        for (int i = 0; i < len1; i++)
        {
            s_map.insert(pair<string, int>(list1[i], i));
        }
        int index = 0;
        int minSumIndex = len1 + len2 - 2;
        for (int i = 0; i < len2; i++)
        {
            map<string, int>::const_iterator it = s_map.find(list2[i]);
            if (it != s_map.cend())
            {
                int minSumTemp = it->second + i;
                if (minSumTemp < minSumIndex)
                {
                    minSumIndex = minSumTemp;
                    index = i;
                }
            }
        }
        for (int i = 0; i < len2; i++)
        {
            int j = minSumIndex - i;
            if (j < 0)
                break;
            if (j >= len1)
                continue;
            if (list1[j] == list2[i])
                res.push_back(list1[j]);
        }
        return res;
    }
};
