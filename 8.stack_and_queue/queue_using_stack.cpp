#include<stack>

class Queue {
    // Define the data members(if any) here.
    stack<int> st;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        stack<int> temp;

        while(!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }

        temp.push(val);

        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st.empty())
        {
            return -1;
        }
        else
        {
            int val = st.top();
            st.pop();
            return val;
        }
    }

    int peek() {
        // Implement the peek() function here.
        if(st.empty())
        {
            return -1;
        }
        else
        {
            return st.top();
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st.empty();
    }
};