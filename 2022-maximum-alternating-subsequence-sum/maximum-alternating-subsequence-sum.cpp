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
            for(int curr_sign = 0;curr_sign < 2;curr_sign++) {

                int val = nums[i];

                if(!curr_sign) {
                    val*=-1;
                }

                long long take = val + dp[i+1][!curr_sign];

                long long not_take = dp[i+1][curr_sign];

                dp[i][curr_sign] = max(take,not_take);
            }
        }
        
        return dp[0][1];
    }
};