/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (min_s.empty())
        {
            min_s.push(x);
            return;
        }
        if (x <= min_s.top())
        {
            min_s.push(x);
        }
    }

    void pop()
    {
        if (s.top() == min_s.top())
            min_s.pop();
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_s.top();
    }

private:
    stack<int> s;
    stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
