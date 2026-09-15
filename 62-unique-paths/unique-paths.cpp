class Solution {
public:

    int solve(int m,int n,int i,int j,vector<vector<int>>&dp) {
        
        
        if(i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
 
        if(i == j && j == 0) {
            return dp[i][j] = 1;
        }

        if( (i == 0) || ( j == 0 )) {
            return dp[i][j] = 1;
        }

        return dp[i][j] = solve(m,n,i-1,j,dp) + solve(m,n,i,j-1,dp);//

    }

    int uniquePaths(int m, int n) {

        //unique paths to reach arr[m-1][n-1] = unique paths to reach arr[m-1-1][n-1] + unique paths to reach arr[m-n][n-1-1].

        
        //Number of unique path to reach i and j depends on the 
        //1.Number of unique path to reach [i-1][j] && [i][j-1].

        //Base case are i = 0 && j = 1 only 1 step to reach it.
        //Base case are i = 1 && j = 0 only 1 step to reach it.

        int i = m-1;
        int j = n-1;

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(m,n,i,j,dp);

        //TC : O(m*n)
        //SC : O(m*n)

    }
};