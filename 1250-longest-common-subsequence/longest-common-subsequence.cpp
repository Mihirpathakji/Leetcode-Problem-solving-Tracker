class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();

        vector<vector<int>>dp(n,vector<int>(m,0));//

        int index1 = -1;    

        for(int i = m-1;i>=0;i--) {
            if(text1[n-1] == text2[i]) {
                index1 = i;
                break;
            }
        }    

        if(index1>=0) {
            for(int i = index1;i>=0;i--) {
                dp[n-1][i] = 1;
            }
        }

        int index2 = -1;
        for(int j = n-1;j>=0;j--) {
            if(text1[j] == text2[m-1]) {
                index2 = j;
                break;
            }
        }    

        if(index2>=0) {
            for(int i = index2;i>=0;i--) {
                dp[i][m-1] = 1;//.
            }   
        }

        for(int i = n-2;i>=0;i--) {
            for(int j = m-2;j>=0;j--) {

                int match = -1;
                
                int not_match = -1;

                if(text1[i] == text2[j]) {
                    match  = 1 + dp[i+1][j+1];
                }
                else {
                    not_match = max(dp[i+1][j],dp[i][j+1]);//
                }
                
                dp[i][j] = max(match,not_match);
            
            }
        }

        return dp[0][0];


    }
};