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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
