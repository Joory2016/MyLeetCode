/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int step[1001];
        int len = cost.size();
        step[0] = 0;
        step[1] = 0;
        if (cost.size() == 0)
            return 0;
        if (cost.size() == 1)
            return cost[0];
        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        for (int i = 2; i <= cost.size(); i++)
        {
            step[i] = min(step[i - 1] + cost[i - 1], step[i - 2] + cost[i - 2]);
        }
        return step[len];
    }
};
