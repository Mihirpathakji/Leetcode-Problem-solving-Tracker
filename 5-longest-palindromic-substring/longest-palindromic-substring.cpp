class Solution {
public:

    bool isPalindrome(vector<vector<int>>&dp,string& s,int i,int j) {

        //Base case for Recursion : 

        if(i >= j) {
            dp[i][j] = 1;
            return true;
        }

        //Memoization : 

        if(dp[i][j] !=-1) {
            return true;
        }

        if(s[i] == s[j]) {

            return isPalindrome(dp,s,i+1,j-1);        
        }

        return false;

    }

    string longestPalindrome(string s) {

        int n = s.length();
        int sp = 0;
        int max_len = INT_MIN;  
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i = 0;i < n;i++) {
            for(int j = i;j < n;j++) {

                //Check whether this substring is Palindrome or not.

                if(isPalindrome(dp,s,i,j) == true) {
                    
                    //Take only the Max lengthed substring.
                    if(max_len < j-i+1) {

                        max_len = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        

        return s.substr(sp,max_len);

        //TC : O(n^2)
        //SC : O(n*2)
        
    }
};