class Solution {
public:
    
    int climbStairs(int n) {

        //3.Bottom Up Approach : 

        //1.Insert the base case into the dp.

        vector<int>dp(n+1,-1);

        dp[0] = 1;
        dp[1] = 1;

        if(n <= 1)
        {
            return 1;
        }

        //2.Move upwards through for loop.

        for(int i = 2;i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

        //TC : O(n)
        //SC : O(n)
        
    }
};