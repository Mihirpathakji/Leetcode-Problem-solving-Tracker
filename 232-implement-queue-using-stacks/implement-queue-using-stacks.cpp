class MyQueue {
public:

    stack<int>st1;//-> To "push" into. 
    stack<int>st2;//-> To "pop" into.

    // Made inside the class . So that Encapsulation is done and For different objects of this class , We can access  the 
    //different sets .

    MyQueue() {

    }   
    
    void push(int x) {
        st1.push(x);
    }
    
   
    int pop() {
        //From st2.
        if(!st2.empty())
        {
            int element = st2.top();
            st2.pop();
            return element;      
        }
        else
        {
            //copy the elements of st1 into st2.
            while(!st1.empty())
            {
                st2.push(st1.top());//1  2 3 4 5
                st1.pop();
            }

            int element = st2.top();// 1
            st2.pop();
            return element;
        }
    }   
    
    int peek() {
        
        //pop-> front element in Queue is always popped.(from st2)
        //front ->  element of the Queue is also peek.(from st2)

        if(!st2.empty())
        {
            return st2.top();
        }
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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