class Solution {
public:

    bool solve(int index,int curr_target,vector<int>& nums,int n,vector<vector<int>>& dp) {

        //f(index,target) -> From i = index to i = n-1. Can we found a subsequence with sum = target.

        if(index >= n) {
            return 0;
        }

        if(dp[index][curr_target]!=-1) {
            return dp[index][curr_target];
        }

        if(index == n-1) {
            //from n-1 index to n-1 index we need to make this target.It can be made only if the
            //arr[n-1] = target itself.

            if(nums[n-1]==curr_target) {
                return dp[n-1][curr_target] = 1;
            }
            else 
            {
                return dp[n-1][curr_target] = 0;
            }
        }

        bool take = false;

        //When we can take that element ?? Suppose we are at arr[index].And now req target sum has reduced down to "target".Now , we need only amount == target inorder to get the target achived.

        //We need sum exactly equal to target. Adding more than target will increase our sum beyond the needed value.If we will take element only if it is <= target.

        if(nums[index] <= curr_target) {
            take = solve(index+1,curr_target-nums[index],nums,n,dp); 
        }   

        bool not_take = false;//

        not_take = solve(index+1,curr_target,nums,n,dp);//we are not takingn the nums[index].So from index+1 to n-1 we need the same target value.

        return dp[index][curr_target] = (take||not_take);
    
    }


    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        int index = 0;//We span possibilities from 0th index till n-1 index.

        //Memoized : 

        for(int i = 0;i < n;i++) {
            sum += nums[i];
        }

        if(sum%2 != 0) {
            return false;
        }

        int target = sum/2; 

        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        
        return dp[index][target] = solve(index,target,nums,n,dp);//(0,s/2,nums)->BIGGEST SUBPROIBLEM.

        //from 0th till n-1 can we get the subsequence sum = s/2.

        //f(0,target) -> from 0th index till n-1(last index) can we make a target.
 
    }
};