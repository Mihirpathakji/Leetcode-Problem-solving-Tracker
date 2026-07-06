class Solution {
public:

    void get_money(vector<int>& dp,vector<int>&nums) {

        for(int i = 2;i < nums.size();i++) {
            dp[i] = max(nums[i]+ dp[i-2],dp[i-1]);
        }

    }
    
    int rob(vector<int>& nums) {

        int n = nums.size();
        //Bottom - Up : 

        vector<int>dp(n+1,-1);
        dp[0] = nums[0];

        if(n == 1) {
            return dp[0];
        }

        dp[1] = max(dp[0],nums[1]);

        get_money(dp,nums);

        return dp[n-1];

        //TC : O(n)
        //SC : O(n)

        
    }
};