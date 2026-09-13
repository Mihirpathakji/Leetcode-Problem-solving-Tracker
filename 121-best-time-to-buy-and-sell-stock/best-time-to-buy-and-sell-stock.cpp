class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int i = 0;
        int j = n-1;

        //Finding the Next Greater using stack for each element.

        stack<int>st;
        st.push(prices[n-1]);

        int max_profit = 0;//0.

        for(int i = n-2;i>=0;i-- ) {

            while(!st.empty() && st.top()<=prices[i]) {
                st.pop();
            }

            if(!st.empty())
            max_profit = max(max_profit,st.top()-prices[i]);
            
            if(st.empty())
            st.push(prices[i]);

            else { 
            
                if(st.top() >= prices[i]) {
                    continue;
                }
                else {  
                    st.pop();
                    st.push(prices[i]);
                }
            }


        }

        return max_profit;

        
    }
};