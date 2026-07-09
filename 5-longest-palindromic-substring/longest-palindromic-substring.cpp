class Solution {
public:

    bool isPalindrome(vector<vector<int>>&dp,string& s,int i,int j) {

        //Base case for Recursion : 

        if(i >= j) {
            dp[i][j] = 1;
            return true;
        }//O(1)

        //Memoization :- 

        if(dp[i][j] !=-1) {
            return true;
        }//O(1)
        
        if(s[i] == s[j]) {

            //Check if same at every points inside the substring.

            if(isPalindrome(dp,s,i+1,j-1)) {
                dp[i][j] = 1;
                return true;
            }//O(1).
            
            else {
                return false;
            }
            
        }

        return false;

    }

    string longestPalindrome(string s) {

        int n = s.length();
        int sp = 0;
        int max_len = INT_MIN;//to give longest one.
        vector<vector<int>>dp(n,vector<int>(n,-1));//stores that [i,j] substring is a palidnrome or not.

        for(int i = 0;i < n;i++) {

            for(int j = i;j < n;j++) {

                //Check whether this substring is Palindrome or not.

                if(isPalindrome(dp,s,i,j) == true) {
                    
                    //Take only the Max lengthed substring.
                   
                    if(max_len < j-i+1) {

                        max_len = j-i+1;//1 "b" 3 //1 3 7
                        sp = i;//0 0 0 0
                    }
                }
            }

        }
        

        return s.substr(sp,max_len);

        //TC : O(n^2)

        /*  
            Total Time Complexity of the Dp soln is :

            Total_work_done_over_all_NON_RECURSIVE_STEPS * Total_Dp_States.

            == O(1)*(O(n^2)).Since dp can have states for all possible n^2 [l,r] substrings.
        
        */



        //SC : O(n*2)
        
    }
};