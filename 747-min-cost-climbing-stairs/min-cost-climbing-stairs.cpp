class Solution {
public:


    int my_min_cost(int n,vector<int>&dp,vector<int>cost)
    {   
        if(n <= 1)
        {
            return dp[n] = 0;//0 steps require to start from 0th or 1th step.
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        return dp[n] = min(cost[n-1] + my_min_cost(n-1,dp,cost) ,cost[n-2] + my_min_cost(n-2,dp,cost));

    }

    int minCostClimbingStairs(vector<int>& cost) {

        //2.Top Down Approach :
        int n = cost.size();
        vector<int>dp(n+1,-1);//f(0)
        
        return my_min_cost(n,dp,cost);

    }
};