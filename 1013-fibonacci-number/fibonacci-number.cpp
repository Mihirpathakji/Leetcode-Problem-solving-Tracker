class Solution {
public:

    int myfib(int n ,vector<int>& dp)
    {
        
        if(n <= 1)
        {
            return n;
        }

        //Already calculated use it:         
        if(dp[n]!=-1)
        {
            return dp[n];
        }
    
        return dp[n] = fib(n-1) + fib(n-2);
    }

    int fib(int n) {

        //Top down approach :

        vector<int>dp(n+1,-1);

        return myfib(n,dp);//compute at n first.

        //TC : O(n)
        //SC : O(2*n)//vector + recursion call stack size == n + n == 2*n 

    }
};