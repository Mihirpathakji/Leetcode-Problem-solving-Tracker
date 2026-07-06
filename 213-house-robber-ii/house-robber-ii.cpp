class Solution {
public:

    int rob(vector<int>& nums) {

        //Bottom - Up : 

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        if(n == 2) {
            return max(nums[0],nums[1]);
        }

        vector<int>dp(n,-1);

        dp[0] = nums[0];
     
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2;i < n-1;i++) {
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        }

        int maxi1 = dp[n-2];//2

        //1 to n-1 th.

        vector<int>temp(n,0);
        for(int i = 0;i < n-1;i++) {
            temp[i] = nums[i+1]; 
        }

        dp[0] = temp[0];
        dp[1] = max(temp[0],temp[1]);

        for(int i = 2;i < n-1;i++) {
            dp[i] = max(temp[i] + dp[i-2],dp[i-1]);
        }

        maxi1 = max(maxi1,dp[n-2]);

        return maxi1;

        //TC : O(n)
        //SC : O(n)

    }
};