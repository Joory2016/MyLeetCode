/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        if (q.empty())
        {
            q.push(x);
            return;
        }
        queue<int> temp;
        temp.push(x);
        while (!q.empty())
        {
            temp.push(q.front());
            q.pop();
        }
        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int temp = q.front();
        q.pop();
        return temp;
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        if (q.empty())
            return true;
        return false;
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
