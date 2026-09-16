class Solution {
public:

    int solve(vector<vector<int>>&dp,int index1,int index2,string& text1,string& text2,int& n,int& m) {

        if(index1 >= n || index2 >= m) {
            return 0;
        }

        if(dp[index1][index2]!=-1) {
            return dp[index1][index2];
        }

        //match :

        if(text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + solve(dp,index1+1,index2+1,text1,text2,n,m);
        }

        // not match : 

        return dp[index1][index2] = max(solve(dp,index1+1,index2,text1,text2,n,m),solve(dp,index1,index2+1,text1,text2,n,m));

    }

    int longestCommonSubsequence(string text1, string text2) {

        int index1 = 0;
        int index2 = 0;

        int n = text1.length();
        int m = text2.length();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(dp,index1,index2,text1,text2,n,m);
        
    }
};