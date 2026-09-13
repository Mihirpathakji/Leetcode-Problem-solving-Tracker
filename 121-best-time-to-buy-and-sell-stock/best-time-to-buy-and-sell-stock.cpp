class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int i = 0;
        int j = n-1;

        int max_profit = 0;
        
        int right_max = prices[n-1];

        for(int i = n-2;i>=0;i-- ) {

            max_profit = max(max_profit,right_max-prices[i]);

            right_max = max(right_max,prices[i]);
        }

        return max_profit;

        //TC : O(n)
        //SC : O(1)
        
    }
};