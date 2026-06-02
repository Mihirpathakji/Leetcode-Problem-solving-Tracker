class Solution {
public:

    int fib(int n) {

        //Bottom - Up approach 

        vector<int>dp(n+1);

        //Compute base case first.
       
        dp[0] = 0;
        
        if(n >=1) 
        dp[1] = 1;

        //Than go upwards.Replace func by dp[i]

        for(int i = 2; i <= n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        } 

        return dp[n];

        //TC : O(n)
        //SC : O(n) -> only vector size of n 
    
    }

};