class Solution {
public:
    void push(int value) {
        stackInt.push(value);
        if (stackMin.empty()||value < stackMin.top())
        {
            stackMin.push(value);
        }
        else
        {
            stackMin.push(stackMin.top());
        }
    }
    void pop() {
        if (!stackInt.empty())
        {
            stackInt.pop();
            stackMin.pop();
        }
    }
    int top() {
        return stackInt.top();
    }
    int min() {
        return stackMin.top();
    }
private:
    stack<int> stackInt;
    stack<int> stackMin;
};
