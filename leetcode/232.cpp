class MyQueue {
public:
    stack<int> stk;
    stack<int> que;

    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        if(que.empty()){
            while(!stk.empty()){
                que.push(stk.top());
                stk.pop();
            }
        }

        int temp = que.top();
        que.pop();
        return temp;
    }
    
    int peek() {
        //if(stk.empty())
        //    return -1;
        if(que.empty()){
            while(!stk.empty()){
                que.push(stk.top());
                stk.pop();
            }
        }

        return que.top();
    }
    
    bool empty() {
        if(que.empty() && stk.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */