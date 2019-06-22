/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
class MyCompare
{
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
};

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), MyCompare());

        int shootNum = 1;
        int shoot_begin = points[0][0];
        int shoot_end = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= shoot_end)
            {
                shoot_begin = points[i][0];
                if (shoot_end > points[i][1])
                    shoot_end = points[i][1];
            }
            else
            {
                shootNum++;
                shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
        }
        return shootNum;
    }
};
