class Solution {
public:

    bool canPartition(vector<int>& nums) {

        //Bottom UP APPROACH : 

        int n = nums.size();//SMALLER SUBPROBLEM : n-1 index to n-1 index find ther answer.

        int sum = 0;

        for(int i = 0;i < n;i++) {
            sum += nums[i];
        }

        if(sum%2 != 0) {
            return false;
        }

        int target = sum/2;

        vector<vector<int>>dp(n,vector<int>(target+1,0));

        if(nums[n-1] == target) {
            dp[n-1][target] = 1;
        }

        for(int i = 0;i < n;i++) {
            dp[i][0] = 1;
        }

        for(int index = n-2;index >=0;index--) {
            for(int target1 = target;target1>=0 ;target1--) {

                bool not_take = dp[index+1][target1];
                bool take = false;

                if(nums[index] <= target1) {
                    take = dp[index+1][target1-nums[index]];
                }
                
                dp[index][target1] = (take || not_take);
            }
        }

        return dp[0][target];

    }
};