class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //3.Bottom Up Approach : 
        //1.start inserting the base cases into the dp :

        int n = cost.size();

        vector<int>dp(n+1,-1);

        dp[0] = 0;//0  coins are require to reach the 0th step.

        dp[1] = 0;//0 coins are require at minimum to start from the 1th step.Since we can "start" from 1th step also.


        //3.for loop replace functions by dp : 

        for(int i = 2; i <= n; i++)
        {
            //cost to went to ith step:
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        
        return dp[n];


        //TC : O(n)
        //SC : O(n)


    }
};