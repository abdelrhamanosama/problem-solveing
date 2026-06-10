// Last updated: 6/10/2026, 11:49:37 AM
class MyQueue {
public:
    int qq[20] = { };
    int front   = 0 , reer = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        qq[reer] = x;
        reer++;
        // return NULL;
    }
    
    int pop() {
        return qq[front++];
    }
    
    int peek() {
        return qq[front];
    }
    
    bool empty() {
        return front == reer;
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