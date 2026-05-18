class StockSpanner {
public:

    vector<int> arr;
    stack<int> st;

    StockSpanner() {

    }

    int next(int price) {

        arr.push_back(price);

        int i = arr.size() - 1;

        // Remove all smaller/equal elements
        while(!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        int nextGreaterOnLeft;

        // No greater element on left
        if(st.empty())
        {
            nextGreaterOnLeft = -1;
        }
        else
        {
            nextGreaterOnLeft = st.top();
        }

        st.push(i);

        return i - nextGreaterOnLeft;
    }
};