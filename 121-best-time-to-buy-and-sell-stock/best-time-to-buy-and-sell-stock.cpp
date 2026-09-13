class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int i = 0;
        int j = n-1;

        int max_profit = 0;//0.//0.
        
        int right_max = prices[n-1];//1.//4.//1.

        int best_i = n-2;//4.//3.
        int best_j = n-1;//5..//4.

        int right_max_index = n-1;//At every iteration the right_max_index == index of the right_max element.

        for(int i = n-2;i>=0;i-- ) {

            if(max_profit < right_max-prices[i]) {
                best_i = i;
                best_j = right_max_index;//Index of the right_max element.
                max_profit = right_max - prices[i];
            }

            else {

                if(right_max < prices[i]) {
                    right_max = prices[i];
                    right_max_index = i;
                }
            }

        }

        return max_profit;//

        //TC : O(n)
        //SC : O(1)
        
    }
};