class MinStack {
private:
    stack<int> main_stack;
    stack<int> min_stack;

public:
    MinStack() {}

    void push(int value) {
        main_stack.push(value);

        if (min_stack.empty()) { // first value
            min_stack.push(value);
        } else {
            int curr = min_stack.top();
            min_stack.push(min(curr,value));
        }
    }

    void pop() {
        min_stack.pop();
        main_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */