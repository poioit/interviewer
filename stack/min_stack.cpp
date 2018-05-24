//https://leetcode.com/problems/min-stack/description/
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int x) {
        // keep min in another stack
        // stk: 1, 2, 3  mini: 1
        // stk 3, 2, 1  mini: 3, 2, 1
        // stk: 1, 1, 3 mini: 1, 1
        if (mini.empty() || x <= mini.top()) {
            mini.push(x);
        }
        stk.push(x);
    }
    
    void pop() {
        if (stk.top() == mini.top())
            mini.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        if (mini.empty())
            return INT_MIN;
        else
            return mini.top();
    }
};