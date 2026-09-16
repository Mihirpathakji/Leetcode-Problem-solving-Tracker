class Solution {
public:
   
    long long maxAlternatingSum(vector<int>& nums) {

        //Bottom Up : 

        int n = nums.size();

        //start at index = n-1.and start forming subsequence and see what max sum that can be achived.

        vector<vector<long long>>dp(n,vector<long long>(2,-1));

        dp[n-1][1] = nums[n-1]; 
        dp[n-1][0] = 0;

        for(int i = n-2;i>=0;i--) {
            //all array indices.thi subsequence start karine joyu.
            for(int index = 0;index < 2;index++) {

                int val = nums[i];

                if(!index) {
                    val*=-1;
                }

                long long take = val + dp[i+1][!index];

                long long not_take = dp[i+1][index];

                dp[i][index] = max(take,not_take);
            }
        }
        
        return dp[0][1];
    }
};