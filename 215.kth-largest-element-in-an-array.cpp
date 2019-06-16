/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> Q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Q.size() < k)
                Q.push(nums[i]);
            else if (Q.top() < nums[i])
            {
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};

/*
bool myComp(int a, int b)
{
    return a > b;
}

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), myComp);
        return nums[k - 1];
    }
}; 
*/
