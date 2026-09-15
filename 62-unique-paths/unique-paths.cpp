class Solution {
public:

    int uniquePaths(int m, int n) {

        //unique paths to reach arr[m-1][n-1] = unique paths to reach arr[m-1-1][n-1] + unique paths to reach arr[m-n][n-1-1].

        
        //Number of unique path to reach i and j depends on the 
        //1.Number of unique path to reach [i-1][j] && [i][j-1].

        //Base case are i = 0 && j = 1 only 1 step to reach it.
        //Base case are i = 1 && j = 0 only 1 step to reach it.

        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int j = 0;j < n;j++) {
            dp[0][j] = 1;
        }

        for(int i = 0;i < m;i++) {
            dp[i][0] = 1;
        }

        for(int i = 1;i < m;i++) {
            for(int j = 1;j < n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    }
};