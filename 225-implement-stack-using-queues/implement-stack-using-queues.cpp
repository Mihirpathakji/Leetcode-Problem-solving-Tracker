class MyStack {
public:

    queue<int>q1;
    queue<int>q2;

    MyStack() {
        
    }
    
    void push(int x) {

        //both empty: you can push into any let's do into Queue1.
        
        if(empty())
        {
            q1.push(x);
        }
        //jisme elements already present ho usme push karo.
        else if(!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }
    
    int pop() {

        if(!q1.empty())
        {
            //q1 = [1 2 3]  q2 empty hase.
            while(q1.size()!=1)
            {
                q2.push(q1.front());
                q1.pop();
            }       
            //q1 = [3]  q2 = [1 2]
            int element = q1.front();
            q1.pop();
            return element;
        }
        else
        {
            while(q2.size()!=1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int element = q2.front();
            q2.pop();
            return element;
        }

    }
    
    int top() {

        if(!q1.empty())
        {
            return q1.back();
        }
        else
        {
            return q2.back();
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */