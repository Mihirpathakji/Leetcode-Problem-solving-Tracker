class Solution {
public:

    bool solve(int index,int curr_target,vector<int>& nums,int n,vector<vector<int>>& dp) {

        //f(index,target) -> from that index till index = n-1. Is target sum achvievable.

        if(dp[index][curr_target]!=-1) {
            return dp[index][curr_target];
        }

        if(index == n-1) {
            if(nums[n-1]==curr_target) {
                return dp[n-1][curr_target] = 1;
            }
            else 
            {
                return dp[n-1][curr_target] = 0;
            }
        }

        bool take = false;

        if(nums[index] <= curr_target) {
            take = solve(index+1,curr_target-nums[index],nums,n,dp); 
        }   

        bool not_take = false;

        not_take = solve(index+1,curr_target,nums,n,dp);

        return dp[index][curr_target] = (take||not_take);
    
    }


    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        //TOP DOWN APPROACH : 
        //start from 0th till n-1 -> bigger.

        int sum = 0;
        int index = 0;

        for(int i = 0;i < n;i++) {
            sum += nums[i];
        }

        if(sum%2 != 0) {
            return false;
        }

        int target = sum/2; 

        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        //Max access -> dp[n-1][target] -> 
        
        return dp[index][target] = solve(index,target,nums,n,dp);
 
    }
};