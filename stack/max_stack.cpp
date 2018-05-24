//https://leetcode.com/problems/max-stack/description/
// in this implementation popMax() is O(n)
class MaxStack {
    stack<int> stk;
    stack<int> stk_max;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (stk_max.empty() || x >= stk_max.top())
            stk_max.push(x);
    }
    
    int pop() {
        int top = stk.top();
        stk.pop();
        if (!stk_max.empty() && stk_max.top() == top)
            stk_max.pop();
        return top;
    }
    
    int top() {
        if (stk.empty())
            return -1;
        return stk.top();
    }
    
    int peekMax() {
        if (stk_max.empty())
            return -1;
        return stk_max.top();
    }
    
    int popMax() {
        if (stk_max.empty())
            return -1;
        stack<int> tmp;
        int ret = stk_max.top();
        while (!stk.empty() && stk.top() != ret) {
            tmp.push(stk.top());
            stk.pop();
        }
        if (!stk.empty())
            stk.pop();
        if (!stk_max.empty())
            stk_max.pop();
        
        while (!tmp.empty()) {
            // may generate new max if stk_max is empty
            push(tmp.top());
            tmp.pop();
        }
        return ret;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */