/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (max_heap.empty())
        {
            max_heap.push(num);
            return;
        }
        if (max_heap.size() == min_heap.size())
        {
            if (num < max_heap.top())
                max_heap.push(num);
            else
            {
                min_heap.push(num);
            }
        }
        else if (max_heap.size() > min_heap.size())
        {
            if (num > max_heap.top())
                min_heap.push(num);
            else
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
        else if (max_heap.size() < min_heap.size())
        {
            if (num < min_heap.top())
                max_heap.push(num);
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }
    }

    double findMedian()
    {
        double res = 0;
        if (max_heap.size() == min_heap.size())
            res = (max_heap.top() + min_heap.top()) / 2.0;
        else if (min_heap.size() > max_heap.size())
            res = min_heap.top();
        else
            res = max_heap.top();
        return res;
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
};

/* 
class MedianFinder
{
public:
    /** initialize your data structure here. 
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        v.push_back(num);
    }

    double findMedian()
    {
        int len = v.size();
        if (len == 1)
            return v[0];
        sort(v.begin(), v.end());
        if (len & 0x1 == 1)
            return v[len / 2];
        else
        {
            double res = (v[len / 2 - 1] + v[len / 2]) / 2.0;
            return res;
        }
    }

private:
    vector<int> v;
};
*/
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
