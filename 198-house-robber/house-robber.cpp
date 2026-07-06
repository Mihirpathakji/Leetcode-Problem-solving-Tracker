class Solution {
public:


    int rob(vector<int>& nums) {

        //Bottom Up :

        int n = nums.size();
        vector<int>dp(n+1,-1);
        
        //1.Initialize the dp with base cases : 

        dp[0] = nums[0];//Max money that can be obtained by robbing houses from 0th till 0th house.

        if(n == 1) {
            return dp[0];
        }

        dp[1] = max(nums[0],nums[1]);//Max money that can be obtained by robbing house from 0th till 1th.

        //dp[i] = Max money that can be obtained by robbing houses from 0th till ith house.

        for(int i = 2;i < n;i++) {
            dp[i] = max(nums[i] + dp[i-2] , dp[i-1]); 
        }

        return dp[n-1];//Max money obtained by robbing from 0th till n-1 houses.

        //TC : O(n)
        //SC : O(n)

    }
};