class Solution {
public:

    int get_money(vector<int>& dp,vector<int>&nums,int end_index) {

        if(end_index == 0) {
            return dp[end_index] = nums[end_index];
        }

        else if(end_index < 0) {
            return 0;
        }

        if(dp[end_index]!=-1) {
            return dp[end_index];
        }

        return dp[end_index] =max(nums[end_index] + get_money(dp,nums,end_index-2), get_money(dp,nums,end_index-1));

    }
    
    int rob(vector<int>& nums) {

        int n = nums.size();

        int end_index = n-1;

        //Top Down Approach : 

        vector<int>dp(n+1,-1);

        get_money(dp,nums,end_index);

        return dp[end_index];
        
    }
};