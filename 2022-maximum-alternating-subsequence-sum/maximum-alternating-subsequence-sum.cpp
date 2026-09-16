class Solution {
public:
    
    long long solve(vector<vector<long long>>&dp,long long index,bool curr_sign ,vector<int>&nums, long long n) {

        if(index >= n) {
            return 0;
        }

        if(dp[index][curr_sign]!=-1) {
            return dp[index][curr_sign];
        }

        long long val = nums[index];

        if(!curr_sign) {
            val*=-1;
        }

        long long take = val + solve(dp,index+1,!curr_sign,nums,n);

        long long not_take = solve(dp,index+1,curr_sign,nums,n);

        return dp[index][curr_sign] = max(take,not_take);

    }

    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        bool flag = true;//Even.for i = 0.

        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        long long index = 0;

        return solve(dp,index,flag,nums,n);

        //TC : O(n*2)
        //SC : O(n*2)
        
    }
};