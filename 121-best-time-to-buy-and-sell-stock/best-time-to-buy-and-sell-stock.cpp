class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int max_profit = 0;//0.
        
        int right_max = prices[n-1];//4.

        int best_i = n-2;//
        int best_j = n-1;//

        int right_max_index = n-1;//At every iteration the right_max_index == index of the right_max element.//5.

        for(int i = n-2;i>=0;i-- ) {

            //this {i,right_max_index} is giving the maximum profit.

            if(max_profit < right_max-prices[i]) {
                best_i = i;//
                best_j = right_max_index;//Index of the right_max element.
                //
                max_profit = right_max - prices[i];//
            }

            if(prices[i] > right_max) {
                right_max = prices[i];
                right_max_index = i;
            }

        }

        return max_profit;//

        //TC : O(n)
        //SC : O(1)
        
    }
};